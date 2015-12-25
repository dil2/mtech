BEGIN{
	tcpsent=0;
	udpsent=0;
	tcprecv=0;
	udprecv=0;
}
{
	if($1=="-" && $3=="0")
	{
		tcpsent++;
	}
	if($1=="r" && $4=="4")
	{
		tcprecv++;
	}
	if($1=="-" && $3=="2")
	{
		udpsent++;
	}
	if($1=="r" && $4=="5")
	{
		udprecv++;
	}	
}
END{
	printf("\nPDF for TCP:%f\n",tcprecv/tcpsent);
	printf("\nPDF for UDP:%f\n",udprecv/udpsent);
}
