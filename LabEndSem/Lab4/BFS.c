#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    struct Node* next;
    int val;
}node;

typedef struct Queue {
    int* arr;
    int r,f;
}queue;

queue* initQ(int n) {
    queue* q = (queue*) malloc(sizeof(queue));
    q->arr = (int*) calloc(n,sizeof(int));
    q->r = q->f = -1;
    return q;
}

int empty(queue* q) {
    return q->r == q->f;
}

void enqueue(queue* q, int x) {
    q->arr[++q->r] = x;
}

int dequeue(queue* q) {
    return q->arr[++q->f];
}

node* insertNode(node* prev, int val) {
    node* nn = (node*) malloc(sizeof(node));
    nn->val = val;
    nn->next = prev->next;
    prev->next = nn;
    return prev;
}

// void dfs(node** graph, int* visited, int i, int* pop_order, int col) {
//     printf("%d, ",i); 
//     visited[i] = col;
//     node* temp = graph[i]->next;
//     while(temp) {
//         if(visited[temp->val] == 0) {
//             dfs(graph,visited,temp->val,pop_order,-col);
//         }
//         else if(visited[temp->val] == col) {
//             printf("Not a Bipartite Graph");
//             exit(0);
//         }
//         temp = temp->next;
//     }
//     pop_order[pop_ind++] = i;
// }

// figure it out later man
void bfs(node** graph, int* visited, int i, int col, int par) {
    queue* q = initQ(sizeof(visited)/sizeof(visited[0]) + 1);
    printf("%d, ",i);
    visited[i] = col;
    enqueue(q,i);
    while(!empty(q)) {
        node* temp = graph[dequeue(q)]->next;
        node* temp1 = temp;
        while(temp) {
            if(visited[temp->val] == 0) {
                printf("%d, ",temp->val);
                visited[temp->val] = -col;
                enqueue(q,temp->val);
            }
            else if(visited[temp->val] == col && temp->val != par) {
                printf("\nNot Bipartite");
                exit(0);
            }
            temp = temp->next;
        }
        par = temp1->val;
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
    printf("\nBFS:\n");
    for(int i = 0; i < n; i++) {
        if(visited[i] == 0) {
            bfs(graph,visited,i,1,-1);
        }
    }
    // printf("\nIt is a Bipartite Graph");
    return 0;
}