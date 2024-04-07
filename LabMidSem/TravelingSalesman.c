#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tsp(int i, int n, int** graph, int* perm, int start, int* cost)
{
    if(i == n-1)
    {
        int curr = 0, temp = start;
        for(int i = 0; i < n-1; i++)
        {
            curr += graph[temp][perm[i]];
            temp = perm[i];
        }
        curr += graph[temp][start];
        if(*cost > curr)
        {
            *cost = curr;
        }
        return;
    }
    for(int j = i; j < n-1; j++)
    {
        if(i == j)
        {
            tsp(i+1,n,graph,perm,start,cost);
        }
        else
        {
            swap(&perm[i],&perm[j]);
            tsp(i+1,n,graph,perm,start,cost);
            swap(&perm[i],&perm[j]);
        }
    }
}

int main()
{
    printf("\nEnter the number of vertices:\n");
    int n; scanf("%d",&n);
    int** graph = (int**) calloc(n,sizeof(int*));
    int start = 0, k = 0;
    int* perm = (int*) calloc(n-1,sizeof(int));
    for(int i = 0; i < n; i++)
    {
        graph[i] = (int*) calloc(n,sizeof(int));
        if(i != start) perm[k++] = i;
        for(int j = 0; j < n; j++)
        {
            int x; scanf("%d",&x);
            graph[i][j] = x;
        }
    }
    printf("\n\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    int cost = INT_MAX;
    tsp(0,n,graph,perm,start,&cost);
    printf("\nCost: %d",cost);
    return 0;
}