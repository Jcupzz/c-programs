#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
int nf=10,N=5,tr=0,i=1,x,flag;
srand(time(NULL));
while(i<=nf)
{
x=0;
for(int j=i;j<i+N && j<=nf;j++)
{
printf("Sent Frame %d \n", j);
tr++;
}
for(int j=i;j<i+N && j<=nf;j++)
{
flag = rand()%2;
if(!flag)
{
printf("%d : Acknowledged! \n", j);
x++;
}
else
{
printf("Frame %d Not Received\nRetransmitting Window \n", j);
break;
}
}
printf("\n");
i+=x;
}
printf("Total number of transmissions : %d \n", tr);
return 0;
}
