#include<stdio.h>
void push(int element);
void pop(int element);
void display();
int arr[];
int n,choice,element;
int top=-1;
int main()
{
    printf("Enter the array size: ");
    scanf("%d",&n);
    arr[n];
    do{
    printf("1.Push\n2.Pop\n3.Display\n4.Quit");
    scanf("%d",&choice);
    switch(choice)
    {
        
        case 1:
        printf("Enter the element to push: ");
        scanf("%d",&element);
        push(element);
        break;
        case 2:
        printf("Enter the element to push: ");
        scanf("%d",&element);
        pop(element);
        break;
        case 3:
        display();
        break;
        case 4:
        break;

    }
    }
    while(choice!=4);

    


    return 0;
}


void push(int element)
{
    if(top>=n-1)
    {
        printf("STACK OVERFLOW!");
    }
    else
    {
    top++;
    arr[top] = element;
    }
}
void pop(int element)
{
    if(top<0)
    {
        printf("STACK UNDERFLOW!");
    }
    else{
    arr[top--];    
    }
}
void display()
{
    if(top<0)
    {
        printf("Stack is Empty");
    }
    else{
    printf("\nThe Stack is: ");
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",arr[i]);
    }
    }
}


