set ns [new Simulator]
set tracefile [open lab1.tr w]
$ns trace-all $tracefile
set namfile [open lab1.nam w]
$ns namtrace-all $namfile
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
#0---1
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns queue-limit $n0 $n1 10
#1---2
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns queue-limit $n1 $n2 10
#1---3
$ns duplex-link $n1 $n3 0.2Mb 10ms DropTail
$ns queue-limit $n1 $n3 10
$ns duplex-link-op $n1 $n3 queuePos 0.5
#1---4
$ns duplex-link $n3 $n4 1Mb 10ms DropTail
$ns queue-limit $n3 $n4 10
#1---5
$ns duplex-link $n3 $n5 1Mb 10ms DropTail
$ns queue-limit $n3 $n5 10
#TCP on Node 0
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
#SINK on Node 4
set sink4 [new Agent/TCPSink]
$ns attach-agent $n4 $sink4
#Connect TCP and SINK
$ns connect $tcp0 $sink4
#Set packetSize TCP
$tcp0 set packetSize_ 1500
#CBR on top of TCP
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $tcp0
$cbr0 set packetSize_ 15000
$cbr0 set interval_ 0.2
#UDP on Node 2
set udp2 [new Agent/UDP]
$ns attach-agent $n2 $udp2
#Null on Node 5
set null5 [new Agent/Null]
$ns attach-agent $n5 $null5
#Connect UDP and Null
$ns connect $udp2 $null5
#set UDP packetSize_
$udp2 set packetSize_ 1500
#CBR on top of UDP
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp2
$cbr1 set packetSize_ 15000
$cbr1 set interval_ 0.2
#Flushing data to namfile and tracefile
proc finish {} {
	global ns tracefile namfile
	$ns flush-trace
	close $tracefile
	close $namfile
	exit 0
} 
#Starting traffic
$ns at 0.1 "$cbr0 start"
$ns at 5.0 "$cbr0 stop"
$ns at 0.1 "$cbr1 start"
$ns at 5.0 "$cbr1 stop"
$ns at 10.0 "finish"
$ns run
