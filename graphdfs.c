#include<stdio.h>
#define SIZE 100
char stack[SIZE];
int adj[5][5],top=-1;
void push(int item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}
int pop()
{
	int item;
	if(top <0)
	{
		printf("stack underflow");
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}
int main()
{
    int x,i,j,n=5,visited[20];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&adj[i][j]);
    for(i=0;i<n;i++)
        visited[i]=0;
    push(0);
    visited[0]=1;
    while(top!=-1)
    {
        x=pop();
        printf("%d ",x);
        for(i=0;i<n;i++)
            if(adj[x][i]==1&&visited[i]==0)
                {
                push(i);
                visited[i]=1;
                }
    }    
}



