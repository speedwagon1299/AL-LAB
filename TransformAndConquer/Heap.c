#include <stdio.h>
#include <stdlib.h>

int op = 0;

void topDown(int* arr, int currIndex)
{
    int parent = currIndex/2;
    while(parent >= 1)
    {
	op++;
        if(arr[parent]<arr[currIndex])
        {
            int temp = arr[parent];
            arr[parent] = arr[currIndex];
            arr[currIndex] = temp;

            currIndex = parent;
            parent = currIndex/2;
        }
        else
            return;
    }
}

int main()
{
    int n;
    printf("Enter no. of elements:\n");
    scanf("%d", &n);
    printf("Enter Elements:\n");
    int* h = (int*) calloc(n+1,sizeof(int));
    
    for(int i = 1; i <= n; i++)
    {
        // scanf("%d",&h[i]);
        h[i] = rand()%100;
        topDown(h, i);
		for(int k = 1; k<=i; k++)
			printf("%d ", h[k]);
		printf("\n");
    }
    
    printf("Heapified array:\n");
    
    for(int i = 1; i<=n; i++)
        printf("%d ", h[i]);
    
    printf("\n");
    printf("OP = %d\n", op);
    return 0;
}