set ns [new Simulator]
set tracefile [open lab2.tr w]
$ns trace-all $tracefile
set namfile [open lab2.nam w]
$ns namtrace-all $namfile
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
#Duplex Link Creation
#0---1
$ns duplex-link $n0 $n1 5Mb 20ms DropTail
$ns queue-limit $n0 $n1 20
$ns duplex-link-op $n0 $n1 orient right
#1---2
$ns duplex-link $n1 $n2 5Mb 100ms DropTail
$ns queue-limit $n1 $n2 20
$ns duplex-link-op $n1 $n2 orient right
#2---3
$ns duplex-link $n2 $n3 5Mb 20ms DropTail
$ns queue-limit $n2 $n3 20
$ns duplex-link-op $n2 $n3 orient right
#Setup TCP Variables
Agent/TCP set nam_tracevar_ true
Agent/TCP set window_ 20
Agent/TCP set ssthresh_ 20
#TCP Over Node 0
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
#SINK Over Node 3
set sink3 [new Agent/TCPSink]
$ns attach-agent $n3 $sink3
#Connect TCP and SINK
$ns connect $tcp0 $sink3
#Set packetSize TCP
$tcp0 set packetSize_ 1500
#Setup FTP over TCP
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ftp0 set packetSize_ 150
$ftp0 set interval_ 0.2
#Error Introduction
set err [new ErrorModel]
$ns lossmodel $err $n1 $n2
$err set rate_ .01
#Flushing data to namfile and tracefile
proc finish {} {
	global ns tracefile namfile
	$ns flush-trace
	close $tracefile
	close $namfile
	
	exit 0
} 
#Starting traffic
$ns at 0.1 "$ftp0 start"
$ns at 5.0 "$ftp0 stop"
$ns at 20.0 "finish"
$ns run 
