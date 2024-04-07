#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node* left;
    struct Node* right;
    int val;
}node;

typedef struct
{
    node* head;
}tree;

node* newNode(int val)
{
    node* nn = (node*) malloc(sizeof(node));
    nn->val = val;
    nn->left = nn->right = NULL;
    return nn;
}

node* cca(node* root, int p, int q)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->val == p || root->val == q)
    {
        return root;
    }
    node* left = cca(root->left,p,q);
    node* right = cca(root->right,p,q);
    if(left && right)
    {
        return root;
    }
    if(left)
    {
        return left;
    }
    if(right)
    {
        return right;
    }
    return NULL;
}

int main()
{
    tree* t = (tree*) malloc(sizeof(tree));
    t->head = newNode(12);
    t->head->left = newNode(10);
    t->head->right = newNode(35);
    t->head->left->left = newNode(8);
    t->head->left->right = newNode(20);
    t->head->left->right->left = newNode(22);
    int p = 8, q = 22;
    printf("\nCCA: %d",cca(t->head,p,q)->val);
    return 0;
}