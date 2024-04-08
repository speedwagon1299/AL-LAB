#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int val;
}node;

node* newNode(int val) {
    node* nn = (node*) malloc(sizeof(node));
    nn->val = val;
    nn->next = NULL;
    return nn;
}

node* insertNode(node* prev, int val) {
    node* nn = newNode(val);
    nn->next = prev->next;
    prev->next = nn;
    return prev;
}

node* insert(node* list[], int x, int m) {
    node* temp = list[x%m];
    while(temp->next) {
        if(temp->next->val == x) {
            return list[x%m];
        }
        else if(temp->next->val > x) {
            break;
        } 
        temp = temp->next;
    }
    insertNode(temp,x);
    return list[x%m];
}

void search(node* list[], int key, int ind, int m) {
    node* temp = list[ind];
    while(temp->next) {
        if(temp->next->val == key) {
            printf("\nFound");
            return;
        }
        temp = temp->next;
    }
    printf("\nNot Found");
}

int main() {
    printf("\nEnter the mod val for hash:\n");
    int m; scanf("%d",&m);
    node* list[m]; 
    for(int i = 0; i < m; i++) {
        list[i] = (node*) malloc(sizeof(node));
        list[i]->next = NULL;
    }
    printf("\nEnter the number of elements:\n");
    int n; scanf("%d",&n);
    printf("\nEnter the elements:\n");
    for(int i = 0; i < n; i++) {
        int x; scanf("%d",&x);
        list[x%m] = insert(list,x,m);
    }
    printf("\nFinal list"); 
    for(int i = 0; i < m; i++) {
        node* temp = list[i];
        while(temp->next) {
            printf("\n%d, ",temp->next->val);
            temp = temp->next;
        }
        printf("\n");
    }
    printf("\nEnter the element to be searched for:\n");
    int key;    scanf("%d",&key);
    int ind = key%m;
    search(list,key,ind,m);
    return 0;
}