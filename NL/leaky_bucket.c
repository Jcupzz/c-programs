#include <stdio.h>
int main()
{
int bs,r,n,ip,store=0;
printf("Enter bucket size, outgoing rate, no of inputs: ");
scanf("%d%d%d",&bs,&r,&n);
while(n!=0)
{
printf("\nEnter the incoming packet size: ");
scanf("%d",&ip);
if((store+ip)<=bs)
{
store+=ip;
printf("\nBucket: %d",store);
}
else
printf("\nBucket overflows!....\nBucket: %d \n",store);
if(store<=r)
{
printf("\nBucket leakes with %d packet size",store);
store=0;
}
else
if(store>=r)
{
printf("\nBucket leakes with %d packet size",r);
store-=r;
}
printf("\nBucket: %d",store);
n--;
}
return 0;
}
