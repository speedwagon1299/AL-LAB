#include <stdio.h>
#include <stdlib.h>

int swapcount,compcount;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(int arr[], int n)
{
	swapcount = 0;
	compcount = 0;
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			compcount++;
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				swapcount++;
			}
		}
	}
	printf("\nComparison Count: %d",compcount);
	printf("\nSwap Count: %d",swapcount);
	printf("\nTotal Count: %d",compcount+swapcount);
}

// int main()
// {
// 	printf("\nEnter the number of elements: ");
// 	int n; scanf("%d",&n);
// 	int arr[n];
// 	printf("\nEnter the elements:\n");
// 	for(int i = 0; i < n; i++)
// 	{
// 		scanf("%d",&arr[i]);
// 	}
// 	bubblesort(arr,n);
// 	printf("\nSorted Array: ");
// 	for(int i = 0; i < n; i++)
// 	{
// 		printf("%d ",arr[i]);
// 	}
// 	printf("\n");
// 	return 0;
// }

int main()
{
	printf("\nEnter the number of elements: ");
	int n; scanf("%d",&n);
	int arr[n];
	printf("\nEnter the elements:\n");
	for(int i = 0; i < n; i++)
	{
		arr[i] = rand()%n;
	}
	bubblesort(arr,n);
	printf("\nSorted Array: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}