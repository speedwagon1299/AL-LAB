#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* next;
	int val;
}node;

node* createNode(int val)
{
	node* nn = (node*) malloc(sizeof(node));
	nn-> next = NULL;
	nn->val = val;
	return nn;
}

node* insertNode(node* prev, node* curr)
{
	curr->next = prev->next;
	prev->next = curr;
	return prev;
}

void display(node* graph[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		node* curr = graph[i];
		printf("%d -> ",curr->val);
		curr = curr->next;
		while(curr)
		{
			printf("%d ",curr->val);
			curr = curr->next;
		}
		printf("\n");
	}
}

void displayMat(int** adjMat, int n)
{
	int i,j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			printf("%d ",adjMat[i][j]);
		}
		printf("\n");
	}
}

void dfs(node* graph[], node* curr, int* visited)
{
	if(!curr || visited[curr->val] == 1)	return;
	printf("%d ",curr->val);
	visited[curr->val] = 1;
	dfs(graph,graph[curr->val]->next,visited);
	return;
}

// void dfs(node* graph[], node* curr, int* pushorder, int* poporder, int* visited)
// {
// 	static int k = 0;
// 	static int o = 0;
// 	if(!curr) return;
// 	pushorder[k++] = curr->val;
// 	dfs(graph,graph[curr->next->val],pushorder,poporder,visited);

// }

int main()
{
	printf("\nEnter the number of vertices:\n");
	int n; scanf("%d",&n);	printf("\n");
	node* graph[n];
	int** adjMat = (int**) calloc(n,sizeof(int*));
	int i, m, j, x;
	for(i = 0; i < n; i++)
	{
		printf("\n\nEnter the number of edges for vertex %d:\t",i);
		scanf("%d",&m);	printf("\n");
		graph[i] = createNode(i);
		adjMat[i] = (int*) calloc(n,sizeof(int));
		if(m >= n)
		{
			printf("\nInvalid, taken as size 0\n");
			continue;
		}
		for(j = 0; j < m; j++)
		{
			printf("\nEnter Edge %d:\t",j);
			scanf("%d",&x);	printf("\n");
			adjMat[i][x] = 1;
			node* nn = createNode(x);
			graph[i] = insertNode(graph[i],nn);
		}
	}
	printf("\nAdjacency List:\n");
	display(graph, n);
	printf("\n\nAdjacency Matrix:\n");
	displayMat(adjMat, n);
	printf("\nDFS: \n");
	int* pushorder = (int*) calloc(n,sizeof(int));
	int* poporder = (int*) calloc(n,sizeof(int));
	int* visited = (int*) calloc(n,sizeof(int));
	for(int i = 0; i < n; i++)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			printf("%d ",i);
			dfs(graph,graph[i]->next,visited);
		}
	}	
	return 0;
}