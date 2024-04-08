#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int pop_ind = 0;

typedef struct Node {
    struct Node* next;
    int val;
}node;

node* insertNode(node* prev, int val) {
    node* nn = (node*) malloc(sizeof(node));
    nn->val = val;
    nn->next = prev->next;
    prev->next = nn;
    return prev;
}

void dfs(node** graph, int* visited, int i, int* pop_order, int col, int par) {
    printf("%d, ",i); 
    visited[i] = col;
    node* temp = graph[i]->next;
    while(temp) {
        if(visited[temp->val] == 0) {
            dfs(graph,visited,temp->val,pop_order,-col,graph[i]->val);
        }
        else if(visited[temp->val] == 1 && temp->val != par) {
            printf("\nCycle exists");
            exit(0);
        }
        // else if(visited[temp->val] == col) {
        //     printf("\nNot a Bipartite Graph");
        //     exit(0);
        // }
        temp = temp->next;
    }
    pop_order[pop_ind++] = i;
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
    node** graph = (node**) calloc(n,sizeof(node*));
    for(int i = 0; i < n; i++) {
        graph[i] = (node*) calloc(n,sizeof(node));
        graph[i]->val = i;
        graph[i]->next = NULL;
        for(int j = n-1; j >= 0; j--) {
            if(adjMat[i][j] == 1) {
                graph[i] = insertNode(graph[i],j);
            }
        }
    }
    int* visited = (int*) calloc(n,sizeof(int));
    int* pop_order = (int*) calloc(n,sizeof(int));
    printf("\n\nDFS:\n");
    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            dfs(graph,visited,i,pop_order,1,-1);
        }
    }
    printf("\nPop Order:\n");
    for(int i = 0; i < n; i++) {
        printf("%d, ",pop_order[i]);
    }
    // printf("\nIt is a Bipartite Graph");
    return 0;
}