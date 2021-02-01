#include<stdio.h>
int main(){
    int n;
    printf("Enter the array size: ");
    scanf("%d",&n);
    int arr[n];
    int i,j,temp;
    printf("Enter the array: ");
    for(i = 0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    //sorting
    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
            while ( j > 0 && arr[j-1] > arr[j])
            {	        
                temp     = arr[j];
                arr[j]   = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
    }
    printf("\nSorted array is: ");
    for (i = 0; i <= n - 1; i++)
    {
        printf("\t%d", arr[i]);
    }

    //
    return 0;
}

