#include <stdio.h>
#include <stdlib.h>
#include "DFS.h"

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
		graph[i] = newNode(i);
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
			node* nn = newNode(x);
			insertGraphNode(graph[i],x,n);
		}
	}
	printf("\nAdjacency List:\n");
	display(graph, n);
	printf("\n\nAdjacency Matrix:\n");
	displayMat(adjMat, n);
	pop_ind = 0;
	printf("\nDFS: ");
	int* poporder = (int*) calloc(n,sizeof(int));
	int* visited = (int*) calloc(n,sizeof(int));
	for(int i = 0; i < n; i++)
	{
		if(visited[i] == 0)
		{
			dfs(graph,visited,i,poporder);
		}
	}	
	printf("\nTopological Sorted: ");
	for(int i = n-1; i >= 0; i--)
	{
		printf("%d ",poporder[i]);
	}
	printf("\n");

}