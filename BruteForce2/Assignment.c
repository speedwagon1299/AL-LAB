#include <stdio.h>
#include <stdlib.h>

int opcount;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void updateCost(int** arr, int* perm, int n, int* minCost)
{
    int cost = 0, k = 0;
    opcount++;
    for(int i = 0; i < n; i++)
    {
        cost += arr[k++][perm[i]];
    }
    if(*minCost > cost)  *minCost = cost; 
}

void efficient(int** arr, int* perm, int i, int n, int* minCost)
{
    if(i == n-1)
    {
        printf("\n");
        for(int a = 0; a < n; a++)
        {
            printf("%d ",perm[a]);
        }
        updateCost(arr,perm,n,minCost);
        return;
    }
    for(int j = i; j < n; j++)
    {
        if(i == j) 
        {
            efficient(arr,perm,i+1,n,minCost);
            continue;
        }
        swap(&perm[i],&perm[j]);
        efficient(arr,perm,i+1,n,minCost);
        swap(&perm[i],&perm[j]);
    }
}

void display(int** arr, int n)
{
    printf("\n");
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
    printf("\nEnter number of ppl/jobs:\n");
    opcount = 0;
    int n; scanf("%d",&n);
    int** arr = (int**) calloc(n,sizeof(int*));
    int* perm = (int*) calloc(n,sizeof(int));
    // for(int i = 0; i < n; i++)
    // {
    //     arr[i] = (int*) calloc(n,sizeof(int));
    //     perm[i] = i;
    //     printf("\nEnter the number of jobs for person %d\n",i+1);
    //     for(int j = 0; j < n; j++)
    //     {
    //         printf("\nJob %d: ",j+1);
    //         scanf("%d",&arr[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i = 0; i < n; i++)
    {
        arr[i] = (int*) calloc(n,sizeof(int));
        perm[i] = i;
        for(int j = 0; j < n; j++)
        {
            arr[i][j] = rand()%100;
        }
        printf("\n");
    }
    printf("\nDisplay:");
    display(arr,n);
    printf("\n");
    int minCost = INT_MAX;
    efficient(arr,perm,0,n,&minCost);
    printf("\nMinimum Cost: %d",minCost);
    printf("\nOps: %d",opcount);
    return 0;
}