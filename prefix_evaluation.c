#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 50

char prefix[MAX];
long int stack[MAX];
int top=-1;

void push(int value)
{
    if(top>MAX)
    {
        printf("Stack overflow!!");
    }
    else
    {
        top=top+1;
        stack[top]=value;
    }
}

int pop()
{
    if(top==-1)
    {
        printf("\nStack underflow");
    }
    else
    {
        return stack[top--];
    }    
}


int pre_eval()
{
    int a,b,temp;
    
    for(int i=strlen(prefix)-1;i>=0;i--)
    {
        if(prefix[i]<='9'&&prefix[i]>='0')
        {
            push(prefix[i]-48);
        }
        else
        {
            b=pop();
            a=pop();
            switch(prefix[i])
            {
                case '+': temp=b+a; break;
                case '-': temp=b-a;break;
                case '*': temp=b*a;break;
                case '/': temp=b/a;break;
                case '^': temp=pow(b,a);
            }
            push(temp);
        }
    }
    return stack[top];
}

void main()
{   int value;
    printf("Enter the prefix equation: ");
    gets(prefix);
    value=pre_eval();
    printf("\n%d is the ans",value);
}