#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int opcount = 0;

void merge(int low, int mid, int high, int* arr)
{
	int* temp = (int*) calloc(high-low+1,sizeof(int));
	int p1 = low, p2 = mid+1, i = 0;
	while(p1 <= mid && p2 <= high)
	{
		if(arr[p1] < arr[p2])
		{
			temp[i] = arr[p1];
			p1++;
		}
		else
		{
			temp[i] = arr[p2];
			p2++;
		}
		i++;
	}
	while(p1 <= mid)
	{
		temp[i] = arr[p1];
		i++; p1++;
	}
	while(p2 <= high)
	{
		temp[i] = arr[p2];
		i++; p2++;
	}
	for(int j = low; j <= high; j++)
	{
		arr[j] = temp[j-low];
		opcount++;
	}
	free(temp);
}

void mergeSort(int low, int high, int* arr)
{
	if(low >= high)	return;
	// opcount++;
	int mid = low + (high-low)/2;
	mergeSort(low,mid,arr);
	mergeSort(mid+1,high,arr);
	merge(low,mid,high,arr);
}

int main()
{

	srand(time(0));

	printf("\nEnter the number of elements:\n");
	int n;	scanf("%d",&n);
	int* arr = (int*) calloc(n,sizeof(int));
	for(int i = 0; i < n; i++)
	{
		arr[i] = rand()%n;
		// scanf("%d",&arr[i]);
	}
	mergeSort(0,n-1,arr);
	for(int i = 0; i <= (n-1)/2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[n-i-1];
		arr[n-i-1] = temp;
	}
	opcount = 0;
	printf("\nSorted: ");
	mergeSort(0,n-1,arr);
	for(int i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nOperations Count: \t%d\n",opcount);
}