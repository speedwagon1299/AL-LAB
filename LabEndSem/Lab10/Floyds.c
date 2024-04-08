#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int min(int a, int b) {
    return (b<a)?b:a;
}

void floyd(int** arr, int n) {
    printf("\nAll Pairs Shortest Path:\n");
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                arr[i][j] = min(arr[i][j],arr[i][k] + arr[k][j]);
            }
        }
}

int main() {
    printf("\nEnter the number of vertices:\n");
    int n; scanf("%d",&n);
    printf("\nEnter the graph:\n");
    int** adjMat = (int**) calloc(n,sizeof(int*));
    for(int i = 0; i < n; i++) {
        adjMat[i] = (int*) calloc(n,sizeof(int));
        for(int j = 0; j < n; j++) {
            scanf("%d",&adjMat[i][j]);
        }
    }    
    floyd(adjMat,n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
    return 0;
}