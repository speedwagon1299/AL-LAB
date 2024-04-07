#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
	return (a<b)?a:b;
}

int main()
{
	printf("\nEnter the number of vertices:\n");
	int v;	scanf("%d",&v);
	int graph[v][v];
	for(int i = 0; i < v; i++)
	{
		printf("\nEnter for Vertex %d: ",i);
		for(int j = 0; j < v; j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("\n\nInitial Graph\n");
	for(int i = 0; i < v; i++)
	{
		for(int j = 0; j < v; j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	for(int k = 0; k < v; k++)
	{
		for(int i = 0; i < v; i++)
		{
			for(int j = 0; j < v; j++)
			{
				graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
			}
		}
	}
	printf("\n\nFinal Graph:\n");
	for(int i = 0; i < v; i++)
	{
		for(int j = 0; j < v; j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}