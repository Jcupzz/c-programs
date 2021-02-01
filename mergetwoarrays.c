#include <stdio.h>
void main()
{
	int i, j, t, n, m;
	printf("Enter the size of first array\n");
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("Enter the size of second array\n");
	scanf("%d", &m);
	int b[m];
	printf("Enter the elements\n");
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	int c[(n + m)];
	for (i = 0; i < n + m; i++)
	{
		if (i < n)
			c[i] = a[i];
		else
			c[i] = b[i - n];
		j = i;
		while (j > 0 && c[j] < c[j - 1])
		{
			t = c[j];
			c[j] = c[j - 1];
			c[j - 1] = t;
			j--;
		}
	}
	printf("Sorted array is \n");
	for (i = 0; i < (n + m); i++)
		printf("%d ", c[i]);
}
