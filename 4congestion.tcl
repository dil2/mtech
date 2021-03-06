set ns [new Simulator]
set tracefile [open lab22.tr w]
$ns trace-all $tracefile
set namfile [open lab22.nam w]
$ns namtrace-all $namfile
#Setup Winfile resource for Xgraph
set winFile [open lab22.win w]
#Declare nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
#Setup TCP Parameters
Agent/TCP set nam_tracevar_ true
Agent/TCP set window_ 20
Agent/TCP set ssthresh_ 20
#Create Duplex Links
#0---1
$ns duplex-link $n0 $n1 5Mb 20ms DropTail
$ns queue-limit $n0 $n1 10
#0---2
$ns duplex-link $n1 $n2 0.5Mb 100ms DropTail
$ns queue-limit $n1 $n2 5
$ns duplex-link-op $n1 $n2 queuePos 0.5
#0---3
$ns duplex-link $n2 $n3 5Mb 20ms DropTail
$ns queue-limit $n2 $n3 10
#Set Topology Orientation
$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient right
$ns duplex-link-op $n2 $n3 orient right
#TCP on Node 0
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
#SINK on Node 4
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
#Set packetSize TCP
$tcp0 set packetSize_ 1500
#FTP on top of TCP
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ftp0 set packetSize_ 15000
$ftp0 set interval_ 0.2
#Connect TCP and SINK
$ns connect $tcp0 $sink
#Add a Monitor in NAM Window
$ns add-agent-trace $tcp0 tcp
$ns monitor-agent-trace $tcp0
$tcp0 tracevar cwnd_
$tcp0 tracevar ssthresh_
#Flushing data to namfile and tracefile
proc finish {} {
	global ns tracefile namfile
	$ns flush-trace
	close $tracefile
	close $namfile
	#exec nam lab22.nam
	exit 0
} 
#The PlotWindow Procedure
proc PlotWindow {tcpsource file} {
	global ns
	set time 0.1
	set now [$ns now]
	set cwnd [$tcpsource set cwnd_]
	puts $file "$now $cwnd"
	$ns at [expr $now+$time] "PlotWindow $tcpsource $file"
}
#Starting traffic
$ns at 0.1 "PlotWindow $tcp0 $winFile"
$ns at 0.1 "$ftp0 start"
$ns at 10.0 "$ftp0 stop"
$ns at 20.0 "finish"
$ns run

