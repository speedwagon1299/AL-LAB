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
	nn->left = nn->right = NULL;
	nn->val = val;
	return nn;
}

node* insertNode(node* root, char* str, int i, int val)
{
	if(!root && str[i] == '\0')
	{
		root = newNode(val);
		return root;
	}
	if(str[i] == 'L')
	{
		root->left = insertNode(root->left,str,i+1,val);
	}
	else
	{
		root->right = insertNode(root->right,str,i+1,val);
	}
	return root;
}

void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}

int contains(node* root, int val)
{
	if(!root)	return 0;
	if(root->val == val)
	{
		return 1;
	}
}

void ClosestCommonAncestor(node* root)
{

}

int main()
{
	tree* t = (tree*) malloc(sizeof(tree));
	printf("\nEnter the value of the root node:\n");
	int x; scanf("%d",&x);
	t->head = newNode(x);
	char* str;
	while(1)
	{
		printf("\nValue: ");
		scanf("%d",&x);
		if(x == -1) break;
		printf("\nPath: ");
		str = (char*) calloc(20,sizeof(char));
		scanf("%s",str);
		printf("\n");
		insertNode(t->head,str,0,x);
		free(str);
	}
	printf("\nEnter the two values:\n");
	int a,b; scanf("%d%d",&a,&b);
	ClosestCommonAncestor();
	return 0;
}