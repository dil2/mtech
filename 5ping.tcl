set ns [new Simulator]
set tracefile [open ping.tr w]
$ns trace-all $tracefile
set namfile [open ping.nam w]
$ns namtrace-all $namfile
set n0 [$ns node]
set n1 [$ns node]
$ns duplex-link $n0 $n1 10Mb 30ms DropTail
set ping0 [new Agent/Ping]
$ns attach-agent $n0 $ping0
set ping1 [new Agent/Ping]
$ns attach-agent $n1 $ping1
$ns connect $ping0 $ping1
Agent/Ping instproc recv { from rtt } {

	$self instvar node_
	puts "The node [$node_ id] received a reply from $from with an RTT $rtt"
	 
}
proc finish { } {
	
	global ns tracefile namfile
	$ns flush-trace
	close $tracefile
	close $namfile
	exec ping.nam
	exit 0
}
$ns at 0.1 "$ping0 send"
$ns at 0.2 "$ping0 send"
$ns at 0.3 "$ping0 send"
$ns at 0.1 "$ping1 send"
$ns at 0.2 "$ping1 send"
$ns at 0.3 "$ping1 send"
$ns run

