#include&lt;stdio.h&gt;
#include&lt;sys/types.h&gt;
#include&lt;netinet/in.h&gt;
#include&lt;string.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;unistd.h&gt;
int main()
{
FILE *fp;
int sd,newsd,ser,n,a,cli,pid,bd,port,clilen;
char name[100],fileread[100],fname[100],ch,file[100],rcv[100];
struct sockaddr_in servaddr,cliaddr;
printf(&quot;Enter the port address\n&quot;);
scanf(&quot;%d&quot;,&amp;port);
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd&lt;0)
printf(&quot;Cant create\n&quot;);
else
printf(&quot;Socket is created\n&quot;);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(port);
a=sizeof(servaddr);
bd=bind(sd,(struct sockaddr *)&amp;servaddr,a);
if(bd&lt;0)
printf(&quot;Cant bind\n&quot;);

else
printf(&quot;Binded\n&quot;);
listen(sd,5);
clilen=sizeof(cliaddr);
newsd=accept(sd,(struct sockaddr *)&amp;cliaddr,&amp;clilen);
if(newsd&lt;0)
{
printf(&quot;Cant accept\n&quot;);
}
else
printf(&quot;Accepted\n&quot;);
n=recv(newsd,rcv,100,0);
rcv[n]=&#39;\0&#39;;
fp=fopen(rcv,&quot;r&quot;);
if(fp==NULL)
{
send(newsd,&quot;error&quot;,5,0);
close(newsd);
}
else
{
while(fgets(fileread,sizeof(fileread),fp))
{
if(send(newsd,fileread,sizeof(fileread),0)&lt;0)
{
printf(&quot;Can’t send file contents\n&quot;);
}
sleep(1);
}
if(!fgets(fileread,sizeof(fileread),fp))
{
//when file pointer reaches end of file, file transfer “completed” message is send to accepted client
connection using newsd, socket file descriptor.
send(newsd,&quot;completed&quot;,999999999,0);
}
return(0);
}
}
/*FTP Client*/
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;sys/socket.h&gt;
#include&lt;netinet/in.h&gt;
#include&lt;unistd.h&gt;
int main()
{
FILE *fp;
int csd,n,ser,s,cli,cport,newsd;
char name[100],rcvmsg[100],rcvg[100],fname[100];
struct sockaddr_in servaddr;
printf(&quot;Enter the port&quot;);

scanf(&quot;%d&quot;,&amp;cport);
csd=socket(AF_INET,SOCK_STREAM,0);
if(csd&lt;0)
{
printf(&quot;Error....\n&quot;);
exit(0);
}
else
printf(&quot;Socket is created\n&quot;);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(cport);
if(connect(csd,(struct sockaddr *)&amp;servaddr,sizeof(servaddr))&lt;0)
printf(&quot;Error in connection\n&quot;);
else
printf(&quot;connected\n&quot;);
printf(&quot;Enter the existing file name\t&quot;);
scanf(&quot;%s&quot;,name);
printf(&quot;Enter the new file name\t&quot;);
scanf(&quot;%s&quot;,fname);
fp=fopen(fname,&quot;w&quot;);
send(csd,name,sizeof(name),0);
while(1)
{
s=recv(csd,rcvg,100,0);
rcvg[s]=&#39;\0&#39;;
if(strcmp(rcvg,&quot;error&quot;)==0)
printf(&quot;File is not available\n&quot;);
if(strcmp(rcvg,&quot;completed&quot;)==0)
{
printf(&quot;File is transferred........\n&quot;);
fclose(fp);
close(csd);
break;
}
else
fputs(rcvg,stdout);
fprintf(fp,&quot;%s&quot;,rcvg);
return 0;
}
}
