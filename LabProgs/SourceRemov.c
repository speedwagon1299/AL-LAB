#include <stdio.h>
#include <stdlib.h>
#include "DFS.h"

void indegreeCalc(int** adjMat, int* indegree, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			indegree[i]+= adjMat[j][i];
		}
	}
}

void sourceRem(int** adjMat, int* indegree, int* visited, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(indegree[i] == 0 && visited[i] == 0)
		{
			printf("%d ",i);
			visited[i] = 1;
			for(int j = 0; j < n; j++)
			{
				if(adjMat[i][j]  == 1)	indegree[j]--;
			}
			i = -1;
		}
	}
}

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
	int* indegree = (int*) calloc(n,sizeof(int));
	indegreeCalc(adjMat,indegree,n);
	printf("Indegrees: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ",indegree[i]);
	}
	printf("\n");
	int* visited = (int*) calloc(n,sizeof(int));
	printf("\nSource Removal: ");
	sourceRem(adjMat,indegree,visited,n);
	printf("\n");
	return 0;
}