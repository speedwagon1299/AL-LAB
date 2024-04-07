#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minCost(int i, int n, int** arr, int* ans, int* perm)
{
    if(i == n)
    {
        int cost = 0;
        for(int i = 0; i < n; i++)
        {
            cost += arr[i][perm[i]];
        }
        if(cost < *ans)
        {
            *ans = cost;
        }
        return;
    }
    for(int j = i; j < n; j++)
    {
        if(i == j)
        {
            minCost(i+1,n,arr,ans,perm);
        }
        else
        {
            swap(&perm[i],&perm[j]);
            minCost(i+1,n,arr,ans,perm);
            swap(&perm[i],&perm[j]);
        }
    }
}

int main()
{
    printf("\nEnter the number of people and jobs:\n");
    int n; scanf("%d",&n);
    int** arr = (int**) calloc(n,sizeof(int*));
    int* perm = (int*) calloc(n,sizeof(int));
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter jobs for person %d\n",i+1);
        arr[i] = (int*) calloc(n,sizeof(int));
        perm[i] = i;
        for(int j = 0; j < n; j++)
        {
            int x; scanf("%d",&x);
            arr[i][j] = x;
        }
    }
    int ans = INT_MAX;
    minCost(0,n,arr,&ans,perm);
    printf("\nMinimum Cost: %d",ans);
}