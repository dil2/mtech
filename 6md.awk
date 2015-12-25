BEGIN{
count=0;
}
{
if($1=="2")
count++;
}
END
{
printf("The no.of packet drop is %d",count);
}
