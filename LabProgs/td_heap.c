#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void topDown(int* arr, int ind)
{
	int par = ind/2;
	while(par >= 1)
	{
		opcount++;
		if(arr[par] < arr[ind])
		{	
			swap(&arr[par],&arr[ind]);
			ind = par;
			par = ind/2;
		}
		else	return;
	}
}

int main()
{
	printf("\nEnter the number of elements:\n");
	int n; scanf("%d",&n);
	int* h = (int*) calloc(n+1,sizeof(int));
	printf("\nEnter the elements:\n");
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&h[i]);
		topDown(h,i);
		for(int j = 1; j <= i; j++)
		{
			printf("%d",h[j]);
		}
		printf("\n");
	}
	printf("\nHeapified Array:\n");
	for(int i = 1; i <= n; i++)
	{
		printf("%d",h[i]);
	}
	printf("\nOpcount:\t%d",opcount);
	return 0;
} 