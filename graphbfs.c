#include<stdio.h>
int adj[5][5],queue[20],front=0,rear=-1;

void enqueue(int x)
{
       
       rear++;
       queue[rear]=x;
}

int dequeue()
{
     
      int del_value=queue[front];
      front++;
      return del_value;
}

int main()
{
    int i,j,n=5,visited[20],x;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
        enqueue(0);
        visited[0]=1;
        while(front<=rear)
            {
            x=dequeue();
            printf("%d  ",x);
            for(i=0;i<n;i++)
            {
            if((adj[x][i]==1)&&(visited[i]==0))
                {
                    enqueue(i);
                    visited[i]=1;
                }
            }
        }
}


