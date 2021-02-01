#include <stdio.h>

#define MAX 10
int arr[MAX];
int front = -1;
int rear = -1;
int itemCount=0;

int main()
{
    int i, choice, num, len;

    do
    {
        printf("\nEnter the choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Get Count\n5.Quit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("item Count is: %d",itemCount);
            break;
        case 5:
            break;
        
        default:
            printf("Invalid!!!");
            break;
        }
    } while (choice != 5);
}
void enqueue()
{
    int num;
    printf("Enter the number to enqueue: ");
    scanf("%d", &num);

    if (rear == MAX - 1)
    {
        printf("QUEUE IS FULL!");
    }
    else{
     if(front == -1)
        {
            front = 0;
            
        }  
        rear++;
        arr[rear] = num;
        itemCount++;
    }
}
void dequeue()
{
    if (front == rear + 1||front == -1)
    {
        printf("Queue is Empty!");
    }
    else
    {

        front = front + 1;
        itemCount--;
    }
}
void display()
{
    if (itemCount == 0)
    {
        printf("Queue is empty!");
    }
    else
    {
    printf("The queue is: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }    
    }
    
}