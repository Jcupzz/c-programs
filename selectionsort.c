
#include<stdio.h>
int main()
{
    int size,i,j,temp,smallest;
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the array:\n");
    int arr[size];
    for(i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }
    //sort
    for(i=0;i<size-1;i++)
    {
        smallest = i;
        for(j=i+1;j<size;j++)
        {
            if(arr[smallest]>arr[j])
            {
                smallest = j; 
            }
            if(arr[smallest]!=arr[i])
            {
                temp = arr[smallest];
                arr[smallest] = arr[i];
                arr[i] = temp;
            }
        }
    }
    printf("The sorted array is: ");
    for(i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}

