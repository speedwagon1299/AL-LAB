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
}Tree;

Tree* initTree()
{
	Tree* t = (Tree*) malloc(sizeof(Tree));
	t->head = NULL;
    return t;
}

node* createNode(int val)
{
    node* nn = (node*) malloc(sizeof(node));
    nn->val = val;
    nn->left = nn->right = NULL;
    return nn;
}

void inorder(node* root)
{
    if(!root)   return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}

void preorder(node* root)
{
    if(!root)   return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(!root)   return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->val);
}