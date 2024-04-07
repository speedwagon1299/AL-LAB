#include <stdio.h>
#include <stdlib.h>

int count;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void efficient(int** arr, int* perm, int n, int i, int* minCost)
{
	if(i == n-1)
	{
		int k = 0, currCost = 0;
		count++;
		for(int j = 0; j < n; j++)
		{
			currCost+= arr[k++][perm[j]];
		}
		if(currCost < *minCost)
		{
			*minCost = currCost;
		}
		return;
	}
	for(int j = 0; j < n; j++)
	{
		if(i == j) continue;
		swap(perm+i,perm+j);
		efficient(arr,perm,n,i+1,minCost);
		swap(perm+i,perm+j);
	}
	return;
}

void display(int** arr, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	printf("\nEnter the number of people/jobs:\n");
	int n; scanf("%d",&n);
	int** arr = (int**) calloc(n,sizeof(int*));
	int* perm = (int*) calloc(n,sizeof(int));
	for(int i = 0; i < n; i++)
	{
		arr[i] = (int*) calloc(n,sizeof(int));
		perm[i] = i;
		printf("\nEnter Jobs for Person %d\n",i+1);
		for(int j = 0; j < n; j++)
		{
			printf("\nJob %d: ",j+1);
			scanf("%d",&arr[i][j]);
		}
		printf("\n");
	}
	count = 0;
	printf("\n");
	display(arr,n);
	int minCost = 10000;
	efficient(arr,perm,n,0,&minCost);
	printf("\nMost efficent: %d",minCost);
	printf("\nOperations: %d\n",count);
	return 0;
}