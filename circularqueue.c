#include<stdio.h>
#include<stdlib.h>
int front = -1, rear = -1;
int maxsize;
void main ()
{
  int ch;
  printf ("\nCircular Queue:\nEnter the size of Queue:\n");
  scanf ("%d", &maxsize);
  int queue[maxsize];
  while (ch != 4)
	{

  	printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit");
  	printf ("\nEnter the choice:\n");
  	scanf ("%d", &ch);
  	switch (ch)
    {
    case 1:
      {
    	int item;
    	printf ("Enter the element\n");
    	scanf ("%d", &item);
    	if ((rear + 1) % maxsize == front)
      	{
   	 printf ("\nQueue is full\n");
   	 break;
      	}
    	else if (front == -1 )
      	{
   	 front = 0;
   	 rear = 0;
      	}
       
    	else
      	{
   	 rear = (rear + 1) % maxsize;
      	}
    	queue[rear] = item;
      }
      break;
    case 2:
      {
    	int item;
    	if (front == -1 )
      	{
   	 printf ("\nQueue Empty\n");
   	 break;
      	}
    	else if (front == rear)
      	{
   	 front = -1;
   	 rear = -1;
      	}
    	else
      	front = (front + 1)%maxsize;
    	printf ("\nItem Deleted");
      }
      break;
    case 3:
      {
    	int i;
    	if (front == -1)
      	printf ("\n Queue is Empty!!!\n");
    	else
      	{
    
   	 printf ("\n Items:");
   	 for (i = front; i != rear; i = (i + 1) % maxsize)
   	   {
   	 	printf ("%d ", queue[i]);
   	   }
   	 printf ("%d ", queue[i]);
   	 
      	}
      }
      break;
    case 4:
      exit (0);
      break;
    default:
      printf ("Wrong Choice!!!\n");
    }
	}
}
