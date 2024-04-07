#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* next;
    int val;
}node;

typedef struct
{
    int r,f;
    int* arr;
}queue;

queue* initQ(int n)
{
    queue* q = (queue*) malloc(sizeof(queue));
    q->arr = (int*) calloc(n+1,sizeof(int));
    q->r = q->f = -1;
    return q;
}

int isEmpty(queue* q)
{
    return q->r == q->f;
}

void enqueue(queue* q, int val)
{
    q->arr[++q->r] = val;
    return;
}

int dequeue(queue* q)
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

node* insertNode(node* prev, int val)
{
    node* nn = newNode(val);
    nn->next = prev->next;
    prev->next = nn;
    return nn;
}

void insertGraphNode(node* vertex, int val, int n)
{
    if(vertex->next == NULL)
    {
        vertex->next = newNode(val);
        return;
    }
    node* temp = vertex;
    int flag = 0;
    while(temp->next != NULL)
    {
        if(temp->next->val > val)
        {
            insertNode(temp,val);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 0) insertNode(temp,val);
}

void displayList(node* graph[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d -> ",i);
        node* temp = graph[i]->next;
        while(temp != NULL)
        {
            printf("%d ",temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

void displayMat(int** adjMat, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
}

int pop_ind;

void dfs(node* graph[],int* visited,int i, int poporder[])
{
    printf("%d ",i);
    visited[i] = 1;
    node* temp = graph[i]->next;
    while(temp != NULL)
    {
        if(visited[temp->val] == 0) dfs(graph,visited,temp->val,poporder);
        temp = temp->next;
    }
    poporder[pop_ind++] = i;
}

void bfs(node* graph[],int* visited,int i,int n)
{
    queue* q = initQ(n);
    printf("%d ",i);
    visited[i] = 1;
    enqueue(q,i);
    while(!isEmpty(q))
    {
        int a = dequeue(q);
        node* temp = graph[a]->next;
        while(temp != NULL)
        {
            if(visited[temp->val] == 0)
            {
                printf("%d ",temp->val);
                enqueue(q,temp->val);
                visited[temp->val] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    printf("\nEnter the number of vertices:\n");
    int n,m,x; scanf("%d",&n);
    node* graph[n];
    int** adjMat = (int**) calloc(n,sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        graph[i] = newNode(i);
        adjMat[i] = (int*) calloc(n,sizeof(int));
        printf("\nEnter the number of edges with vertex %d: ",i);
        scanf("%d",&m);
        for(int j = 0; j < m; j++)
        {
            printf("Edge %d: ",j+1);
            scanf("%d",&x);
            adjMat[i][x] = 1;
            insertGraphNode(graph[i],x,n);
        }
    }
    displayList(graph,n);
    printf("\n");
    displayMat(adjMat,n);
    printf("\n\nDFS: ");
    int poporder[n];
    int* visited = (int*) calloc(n,sizeof(int));
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(graph,visited,i,poporder);
        }
    }
    pop_ind = 0;
    printf("\nPoporder: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",poporder[i]);
    }
    free(visited);
    visited = (int*) calloc(n,sizeof(int));
    printf("\n\nBFS: ");
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            bfs(graph,visited,i,n);
        }
    }
    return 0;
}