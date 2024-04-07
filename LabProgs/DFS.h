#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* next;
	int val;
}node;

node* newNode(int val)
{
	node* nn = (node*) malloc(sizeof(node));
	nn-> next = NULL;
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

int pop_ind;
void dfs(node* graph[], int* visited, int i, int poporder[])
{
	printf("%d ",i);
	visited[i] = 1;
	node* temp = graph[i]->next;
	while(temp != NULL)
	{
		if(visited[temp->val] == 0)
			dfs(graph,visited,temp->val,poporder);
		temp=temp->next;
	}
	poporder[pop_ind++] = i;
}


// int main()
// {
// 	printf("\nEnter the number of vertices:\n");
// 	int n; scanf("%d",&n);	printf("\n");
// 	node* graph[n];
// 	int** adjMat = (int**) calloc(n,sizeof(int*));
// 	int i, m, j, x;
// 	for(i = 0; i < n; i++)
// 	{
// 		printf("\n\nEnter the number of edges for vertex %d:\t",i);
// 		scanf("%d",&m);	printf("\n");
// 		graph[i] = newNode(i);
// 		adjMat[i] = (int*) calloc(n,sizeof(int));
// 		if(m >= n)
// 		{
// 			printf("\nInvalid, taken as size 0\n");
// 			continue;
// 		}
// 		for(j = 0; j < m; j++)
// 		{
// 			printf("\nEnter Edge %d:\t",j);
// 			scanf("%d",&x);	printf("\n");
// 			adjMat[i][x] = 1;
// 			node* nn = newNode(x);
// 			insertGraphNode(graph[i],x,n);
// 		}
// 	}
// 	printf("\nAdjacency List:\n");
// 	display(graph, n);
// 	printf("\n\nAdjacency Matrix:\n");
// 	displayMat(adjMat, n);
// 	pop_ind = 0;
// 	printf("\nDFS: \n");
// 	int* pushorder = (int*) calloc(n,sizeof(int));
// 	int* poporder = (int*) calloc(n,sizeof(int));
// 	int* visited = (int*) calloc(n,sizeof(int));
// 	for(int i = 0; i < n; i++)
// 	{
// 		if(visited[i] == 0)
// 		{
// 			dfs(graph,visited,i,poporder);
// 		}
// 	}	
// 	printf("\n");
// 	return 0;
// 