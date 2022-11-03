#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node* left;
	struct node* right;
	int data;
};
struct node* createNode(int);
struct node* search(struct node*,int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
int count_of_nodes(struct node*);
int main()
{
	int key=30;
	struct node*temp;
	struct node* root=NULL;
	root=createNode(50);
	root->left=createNode(30);
	root->right=createNode(60);
	root->left->left=createNode(20);
	root->left->right=createNode(40);
	root->right->left=createNode(55);
	root->right->right=createNode(70);
	 preorder(root);
	 inorder(root);
	 postorder(root);
	 printf("total number of code in binary tree is %d",count_of_nodes(root));
	 return 0;
}

struct node* createNode(int data)
{
	struct node* Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->data=data;
	Newnode->left=NULL;
	Newnode->right=NULL;
	return Newnode;
}
//preorder
void preorder(struct node* root)
{
	if(root==NULL)
		return;
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}
//inorder
void inorder(struct node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d\n",root->data);
	inorder(root->right);
}
//postorder
void postorder(struct node* root)
{ 
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d",root->data);
}
int count_of_nodes(struct node* root)
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL&&root->right==NULL)
		return 1;
	else
	{
		int left =count_of_nodes(root->left);
		int right=count_of_nodes(root->right);
		return(1+right+left);
	}
}














