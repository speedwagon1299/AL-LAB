#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int checkCol(int** adjMat, int col, int n) {
    for(int i = 0; i < n; i++) {
        if(adjMat[i][col] != 0) { 
            return 0;
        }
    }
    return 1;
}

void setZero(int** adjMat, int row, int n) {
    for(int i = 0; i < n; i++) {
        adjMat[row][i] = 0;
    }
}

void sourceRem(int** adjMat, int n, int* visited) {
    for(int i = 0; i < n; i++) {
        if(checkCol(adjMat,i,n) && visited[i] == 0) {
            printf("%d, ",i);
            visited[i] = 1;
            setZero(adjMat,i,n);
            i = -1;
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
    int* visited = (int*) calloc(n,sizeof(int));
    printf("\nSource Removal:\n");
    sourceRem(adjMat,n,visited);
    return 0;
}
