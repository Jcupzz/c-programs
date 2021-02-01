#include <stdio.h>
#include <stdlib.h>
void append();
void display();
void delete ();
struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;
int main()
{

    int choice;

    while (1)
    {
        printf("\nEnter the Choice: \n1.Append\n2.Display\n3.Delete\n4.Length\n5.Insert Inbetween\n6.Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            append();
            break;

        case 2:
            display();
            break;

        case 3:
            delete ();
            break;

        case 4:
        printf("Length is: %d",length());
        break;

        case 5:
        insertInBetween();
        break;

        case 6:
            exit(1);
            break;

        default:
            break;
        }
    }
    return 0;
}
void insertInBetween(){
    struct node *temp,*p;
    int loc;
    int value;
    printf("Enter the location to insert: ");
    scanf("%d",&loc);
    printf("Enter the value to be inserted: ");
    scanf("%d",&value);
   
    if(loc>length())
    {
        printf("Invalid Location");
    }
    else
    {
        p = root;
        int i=1;
        while (i<loc-1)
        {
            p = p->link;
            i++;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = value;
        temp->link = NULL;
        temp->link = p->link;
        p->link = temp;
        
    }
    
}
void append()
{
    int value;

    printf("\nEnter the Number to Append: ");
    scanf("%d", &value);

    struct node *temp;
    temp = malloc(sizeof(struct node));

    temp->data = value;
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *ptr;
        ptr = root;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}
void display()
{
    struct node *temp;
    temp = root;

    if (temp == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
    }
}
int length()
{
    int count = 0;
    struct node *temp;
    temp = root;

    if (temp == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->link;
            count++;
        }
    }

    return count;
}
void delete ()
{
    int loc;
    struct node *p, *q, *temp;
    printf("\nEnter the location to be deleted: ");
    scanf("%d", &loc);

    if (loc > length())
    {
        printf("\nInvalid Location");
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        int i = 1;
        p = root;
        while (i < loc - 1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
}