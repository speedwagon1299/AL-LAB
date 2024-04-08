#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int h;
    int val;
}node;

node* createNode(int val) {
    node* nn = (node*) malloc(sizeof(node));
    nn->left = nn->right = nn->parent = NULL;
    nn->h = 1;
    nn->val = val;
    return nn;
}

int max(int a, int b) {
    return (a>b)?a:b;
}

int height(node* root) {
    return (root)?(root->h):0;
}

int getBalance(node* root) {
    if(!root)   return 0;
    return height(root->left) - height(root->right);
}

node* rotateRight(node* a) {
    node* b = a->left;
    node* c = b->right;
    b->right = a;
    a->parent = b;
    a->left = c;
    if(c)   c->parent = a;
    a->h = max(height(a->left),height(a->right)) + 1;
    b->h = max(height(b->left),height(b->right)) + 1;
    return b;
}

node* rotateLeft(node* a) {
    node* b = a->right;
    node* c = b->left;
    b->left = a;
    a->parent = b;
    a->right = c;
    if(c)   c->parent = a;
    a->h = max(height(a->left),height(a->right)) + 1;
    b->h = max(height(b->left),height(b->right)) + 1;
    return b;
}

node* insertNode(node* root, int val) {
    if(root == NULL) {
        return createNode(val);
    }
    if(root->val == val) {
        return root;
    }
    else if(val < root->val) {
        root->left = insertNode(root->left,val);
        if(root->left) root->left->parent = root;
    }
    else {
        root->right = insertNode(root->right,val);
        if(root->right) root->right->parent = root;
    }
    root->h = max(height(root->left),height(root->right)) + 1;
    int bal = getBalance(root);
    if(bal > 1 && val < root->left->val) {  // LL
        return rotateRight(root);
    }
    else if(bal > 1 && val > root->left->val) { //LR
        root->left = rotateLeft(root->left);
        root->left->parent = root;
        return rotateRight(root);
    }
    else if(bal < -1 && val > root->right->val) {   //RR
        return rotateLeft(root);
    }
    else if(bal < -1 && val < root->right->val) {   //RL
        root->right = rotateRight(root->right);
        root->right->parent = root;
        return rotateLeft(root);
    }
    return root;
}

void preorder(node* root) {
    if(root) {
        printf("%d, ",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    int arr[6] = {10,20,30,40,50,25};
    node* root = NULL;
    for(int i = 0; i < 6; i++) {
        root = insertNode(root,arr[i]);
    }
    preorder(root);
    return 0;
}
