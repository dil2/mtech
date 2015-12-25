BEGIN{
	byte_rcvd=0;
	time=0;
}
{
	if($1=="r" && $4=="3")
	{
		byte_rcvd=byte_rcvd+$6;
		time=$2;
	}
}
END{
	printf("The throughput is: %f Mbps\n",(byte_rcvd/time)*(8/1000000));
}
