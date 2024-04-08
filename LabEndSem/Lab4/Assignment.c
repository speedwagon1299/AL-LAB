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

void assignment(int** arr, int* perm, int n, int ind, int* bestcost) {
    if(ind == n) {
        int cur_cost = 0;
        for(int i = 0; i < n; i++) {
            cur_cost += arr[i][perm[i]];
        }
        if(cur_cost < *bestcost) {
            *bestcost = cur_cost;
        }
        return;
    }
    for(int i = ind; i < n; i++) {
        swap(&perm[i],&perm[ind]);
        assignment(arr,perm,n,ind+1,bestcost);
        swap(&perm[i],&perm[ind]);
    }

}

int main() {
    printf("\nEnter size of 2D matrix:\n");
    int n; scanf("%d",&n);
    
    printf("\nEnter the 2D matrix with rows indicating Job and columns indicating Person:\n");
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
    assignment(arr,perm,n,0,&cost);
    printf("\nMinimum Cost: %d",cost);
    return 0;
}