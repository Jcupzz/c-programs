#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#define MAX 50

int top = -1;
long int stack[MAX];
char postfix[MAX];
void push(int item)
{
    if (top > 50)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}
int pop()
{
    int n;
    if (top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        n = stack[top];
        top--;

        return (n);
    }
}
int post()
{
    int a, b, temp;
    for (int i = 0; i <= strlen(postfix) - 1; i++)
    {
        if (postfix[i] <= '9' && postfix[i] >= '0')
        {
            push(postfix[i] - 48);
        }
        else
        {
            a = pop();
            b = pop();
            switch (postfix[i])
            {
            case '+':
                temp = a + b;
                break;
            case '-':
                temp = a - b;
                break;
            case '/':
                temp = a / b;
                break;
            case '*':
                temp = a * b;
                break;
            case '^':
                temp = a ^ b;
                break;
            }
            push(temp);
        }
    }
    return (temp);
}
void main()
{
    int value, i;
    printf("Enter postfix expression:");
    gets(postfix);
    value = post();
    printf("After evaluation: %d", value);
}