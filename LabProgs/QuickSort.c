#include <stdio.h>
#include <stdlib.h>

int opcount;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int l, int r, int* arr)
{
	int pivot = arr[l];
	int i = l+1, j = r;
	opcount++;
	while(i < j)
	{
		while(i <= j && arr[i] <= pivot) {i++;opcount++;}
		while(j >= i && arr[j] >= pivot) {j--;opcount++;}
		if(i < j) {swap(&arr[i],&arr[j]);opcount++;}
	}
	if(arr[l] > arr[j])	{swap(&arr[l],&arr[j]);opcount++;}
	return j;
}

void quicksort(int l, int r, int* arr)
{
	if(r-l <= 0)	return;
	int s = partition(l,r,arr);
	quicksort(l,s-1,arr);
	quicksort(s+1,r,arr);
	return;
}

int main()
{
	printf("\nEnter the number of elements: ");
	int n; scanf("%d",&n);
	int* arr = (int*) malloc(n*sizeof(int));
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	opcount = 0;
	quicksort(0,n-1,arr);
	printf("\n\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nOp Count: %d",opcount);
	return 0;
}