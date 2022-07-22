#include<stdio.h>
#include<stdlib.h>
int selective_repeat( int window_size , int frame_size)
{
int nt =0,k = 0,left[20] = {-1},i,flag ;
for(i = 1 ; i <= frame_size ; i++)
{
flag = rand() % 2;
if(flag)
{
printf(" Frame[%d] Acknowledged !!! \n\n", i );
nt++;
}
else
{
printf(" Frame[%d] Not Acknowledged !!! \n\n", i );
left[i] = 1;
nt++;
}
}
for(i = 0 ; i < frame_size; i++)
if(left[i]==1)
{
printf(" Frame[%d] Retransmitted \n\n", i );
nt++;
printf(" Frame[%d] Acknowledged on Second Attempt \n\n", i );
}
printf(" Total Transmissions : %d \n\n", nt);
return 0;
}
int main()
{
int window_size,frame_size;
printf("Enter Window Size : ");
scanf("%d",&window_size);
printf("Enter Number Of Frames To Be Transmitted : \n");
scanf("%d",&frame_size);
selective_repeat(window_size , frame_size);
return 0;
}
