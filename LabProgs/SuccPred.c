#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *left, *right, *parent;
	int val,h;
}node;

node* newNode(int val)
{
	node* nn = (node*) malloc(sizeof(node));
	nn->left = nn->right = nn->parent = NULL;
	nn->val = val; nn->h = 1;
	return nn;
}

int height(node* root)
{
	if(!root)	return 0;
	return root->h;
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

node* rightRotate(node* root)
{
	node* root_left = root->left;
	node* root_left_right = root_left->right;

	root_left->right = root;
	root->parent = root_left;
	
	root->left = root_left_right;
	if(root_left_right) root_left_right->parent = root;
	
	root->h = max(height(root->left),height(root->right)) + 1;
	root_left->h = max(height(root_left->left),height(root_left->right)) + 1;
	
	return root_left;
}

node* leftRotate(node* root)
{
	node* root_right = root->right;
	node* root_right_left = root_right->left;
	
	root_right->left = root;
	root->parent = root_right;
	
	root->right = root_right_left;
	if(root_right_left) root_right_left->parent = root;
	
	root->h = max(height(root->left),height(root->right)) + 1;
	root_right->h = max(height(root_right->left),height(root_right->right)) + 1;
	
	return root_right;
}

int getBalance(node* root)
{
	if(!root)	return 0;
	return height(root->left) - height(root->right);
}

node* insert(node* root, int val)
{
	if(root == NULL)	return newNode(val);
	if(val < root->val)
	{
		root->left = insert(root->left,val);
		root->left->parent = root;
	}
	else if(val > root->val)
	{
		root->right = insert(root->right,val);
		root->right->parent = root;
	}
	else
	{
		return root;
	}
	
	root->h = max(height(root->left),height(root->right)) + 1;
	int bal = getBalance(root);

	if(bal > 1 && val < root->left->val)	//LL
	{
		return rightRotate(root);
	}
	if(bal < -1 && val > root->right->val)	//RR
	{
		return leftRotate(root);
	}
	if(bal > 1 && val > root->left->val)	//LR
	{
		root->left = leftRotate(root->left);
		root->left->parent = root;
		return rightRotate(root); 
	}
	if(bal < -1 && val < root->right->val)	//RL
	{
		root->right = rightRotate(root->right);
		root->right->parent = root;
		return leftRotate(root);
	}
	return root;
}

void preorder(node* root)
{
	if(root)
	{
		printf("%d ",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

node* maxVal(node* root)
{
	while(root->right)	root = root->right;
	return root;
}

node* minVal(node* root)
{
	while(root->left)	root = root->left;
	return root;
}

node* inSucc(node* root)
{
	if(root->right)	return minVal(root->right);
	node* temp = root->parent;
	while(temp && temp->right == root)
	{
		root = temp;
		temp = temp->parent;
	}
	return temp;
}

node* inPred(node* root)
{
	if(root->left)	return maxVal(root->left);
	node* temp = root->parent;
	while(temp && temp->left == root)
	{
		root = temp;
		temp = temp->parent;
	}
	return temp;
}

int main()
{
	printf("\nEnter the number of elements:\n");
	int n; scanf("%d",&n);
	node* head = NULL;
	printf("\nEnter the elements:\n");
	for(int i = 0; i < n; i++)
	{
		int x; scanf("%d",&x);
		head = insert(head,x);
	}
	printf("\nPreorder:\t");
	preorder(head);
	node* temp = head->left->right;
	printf("\nInorder Predecessor of 25: %d\n",inPred(temp)->val);
	printf("\nInorder Successor of 25: %d\n",inSucc(temp)->val);
}