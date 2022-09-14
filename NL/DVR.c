#include <stdio.h>
int main()
{
    int n, count;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    int c[n][n];
    printf("Enter the cost matrix of the nodes:\n  ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {

                continue;
            }
            else
            {
                for (int k = 0; k < n; k++)
                {
                    if (c[i][j] > c[k][j] + c[i][k])
                    {
                        c[i][j] = c[k][j] + c[i][k];
                    }
                }
            }
        }
    }
    printf("The final routing table is: \n  ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}