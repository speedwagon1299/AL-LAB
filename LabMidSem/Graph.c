#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* next;
    int val;
}node;

typedef struct
{
    int* arr;
    int r,f;
}queue;

queue* initQ(int n)
{
    queue* q = (queue*) malloc(sizeof(queue));
    q->arr = (int*) calloc(n+1,sizeof(int));
    q->r = q->f = -1;
}

int isEmpty(queue* q)
{
    return q->r == q->f;
}

void push(queue* q, int x)
{
    q->arr[++q->r] = x;
    return;
}

int pop(queue* q)
{
    return q->arr[++q->f];
}

node* newNode(int val)
{
    node* nn = (node*) malloc(sizeof(node));
    nn->next = NULL;
    nn->val = val;
    return nn;
}

void insert(node* prev, int x)
{
    node* nn = newNode(x);
    nn->next = prev->next;
    prev->next = nn;
}

void insertNode(node** graph, int i, int x)
{
    if(graph[i]->next == NULL)
    {
        graph[i]->next = newNode(x);
        return;
    }
    node* temp = graph[i];
    int flag = 0;
    while(temp->next != NULL)
    {
        if(temp->next->val > x)
        {
            insert(temp,x);
            flag = 1;
            break;
        }
        temp = temp->next;        
    }
    if(flag == 0)
    {
        insert(temp,x);
    }
}

void displayList(node** graph, int n)
{
    printf("\nAdjacency List:\n");    
    for(int i = 0; i < n; i++)
    {
        printf("\n%d: ",i);
        node* temp = graph[i]->next;
        while(temp != NULL)
        {
            printf("%d -> ",temp->val);
            temp = temp->next;
        }
    }
}

void displayMat(int** adjMat, int n)
{
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
}

void dfs(node* vertex, node** graph, int* visited, int* poporder)
{
    static int pop_ind = 0;
    visited[vertex->val] = 1;
    printf("%d ", vertex->val);
    node* temp = graph[vertex->val]->next;
    while(temp != NULL)
    {
        if(visited[temp->val] == 0)
        {
            dfs(temp,graph,visited,poporder);
        }
        temp = temp->next;
    }
    poporder[pop_ind++] = vertex->val;
}

void bfs(node* vertex, node** graph, int* visited, int n)
{
    queue* q = initQ(n);
    printf("%d ",vertex->val);
    push(q,vertex->val);
    visited[vertex->val] = 1;
    while(!isEmpty(q))
    {
        node* temp = graph[pop(q)]->next;
        while(temp != NULL)
        {
            if(visited[temp->val] == 0)
            {
                visited[temp->val] = 1;
                printf("%d ",temp->val);
                push(q,temp->val);
            }
            temp = temp->next;
        }
    }
}

void source(int** adjMat, int* indegree, int* visited, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            indegree[i] += adjMat[j][i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0 && visited[i] == 0)
        {
            printf("%d ",i);
            visited[i] = 1;
            for(int j = 0; j < n; j++)
            {
                if(adjMat[i][j] == 1)
                {
                    indegree[j]--;
                }
            }
            i = -1;
        }
    }
}

int main()
{
    printf("\nEnter the number of vertices:\n");
    int n; scanf("%d",&n);
    node** graph = (node**) malloc(n*sizeof(node*));
    int* visited = (int*) calloc(n,sizeof(int));
    int** adjMat = (int**) calloc(n,sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter number of edges for vertex %d:\n",i);
        int e; scanf("%d",&e);
        adjMat[i] = (int*) calloc(n,sizeof(int));
        graph[i] = newNode(i);
        for(int j = 0; j < e; j++)
        {
            printf("\nEnter edge %d: ",j+1);
            int x; scanf("%d",&x);
            insertNode(graph,i,x);
            adjMat[i][x] = 1;
        }
    }
    printf("\n\n");
    displayList(graph,n);
    printf("\n\n");
    displayMat(adjMat,n);
    printf("\nDFS:\n");
    int* poporder = (int*) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(graph[i],graph,visited,poporder);
        }
    }
    printf("\nPop Order:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",poporder[i]);
    }
    printf("\n");
    free(visited);
    visited = (int*) calloc(n,sizeof(int));
    printf("\nBFS:\n");
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            bfs(graph[i],graph,visited,n);
        }
    }
    int* indegree = (int*) calloc(n,sizeof(int));
    free(visited);
    visited = (int*) calloc(n,sizeof(int));
    printf("\nSource Removal:\n");
    source(adjMat,indegree,visited,n);
    return 0;
}