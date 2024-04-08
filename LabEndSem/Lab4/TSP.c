#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void tsp(int** arr, int* perm, int n, int ind, int start, int* min_cost) {
    if(ind == n-1) {
        int cur_cost = 0, temp = start;
        for(int i = 1; i < n; i++) {
            cur_cost += arr[temp][perm[i]];
            temp = perm[i];
        }
        cur_cost += arr[temp][start];
        if(*min_cost > cur_cost)
        {
            *min_cost = cur_cost;
        }
        return;
    }
    for(int i = ind; i < n-1; i++) {
        swap(&perm[i],&perm[ind]);
        tsp(arr,perm,n,ind+1,start,min_cost);
        swap(&perm[i],&perm[ind]);
    }
}

int main() {
    printf("\nEnter size of 2D matrix:\n");
    int n; scanf("%d",&n);
    
    printf("\nEnter the 2D matrix for travelling salesperson:\n");
    int** arr = (int**) calloc(n,sizeof(int*));
    int* perm = (int*) calloc(n,sizeof(int));
    for(int i = 0; i < n; i++) {
        arr[i] = (int*) calloc(n,sizeof(int));
        perm[i] = i;
        for(int j = 0; j < n; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    
    printf("\nMatrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    int cost = INT_MAX;
    tsp(arr,perm,n,0,0,&cost);
    printf("\nMinimum Cost: %d",cost);
    return 0;
}