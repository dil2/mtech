BEGIN{
	sum=0;	
}
{
	if($1=="r" && $4=="4")
	{
		printf("%f\t%f\n",$2,sum/$2);
		sum=sum+$6;
	}
}
END{
}
