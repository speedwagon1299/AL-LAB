#include <stdio.h>
#include <stdlib.h>

void insert(int* list, int* visited, int x, int m) {
    if(visited[x%m] == 0) {
        visited[x%m] = 1;
        list[x%m] = x;
        return;
    }
    for(int i = (x+1)%m; i != x%m; i = (i+1)%m) {
        if(visited[i] == 0) {
            list[i] = x;
            visited[i] = 1;
            return;
        }
    }
    printf("\nERROR");
    return;
}

void search(int* list, int* visited, int x, int m) {
    if(visited[x%m] == 0) {
        printf("\nNot Found");
        return;
    }
    if(list[x%m] == x) {
        printf("\nFound");
        return;
    }
    for(int i = (x+1)%m; i != x%m; i = (i+1)%m) {
        if(visited[i] == 1) {    
            if(list[i] == x) {
                printf("\nFound");
                return;
            }
        }
        else {
            printf("\nNot Found");
            return;
        }
    }
    printf("\nNot Found");
    return;
}

int main() {
    printf("%d",-10%6);
    printf("\nEnter the mod val for hash:\n");
    int m; scanf("%d",&m);
    int* list = (int*) calloc(m,sizeof(int)); 
    int* visited = (int*) calloc(m,sizeof(int));
    printf("\nEnter the number of elements:\n");
    int n; scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(int i = 0; i < n; i++) {
        int x; scanf("%d",&x);
        insert(list,visited,x,m);
    }
    printf("\nClosed hash:\n");
    for(int i = 0; i < m; i++) {
        printf("%d, ",list[i]);
    }
    printf("\nEnter the element to be searched for:\n");
    int key;    scanf("%d",&key);
    search(list,visited,key,m);
    return 0;
}