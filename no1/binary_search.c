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
	temp=search(root,key);
	if(key==temp->data)
	{
	printf(" number is found in  binary tree %d",temp->data);
	}

	else{
		printf("binary search is not found");
	}	
}

struct node* createNode(int data)
{
	struct node* Newnode=(struct node*)malloc(sizeof(struct node));
	Newnode->data=data;
	Newnode->left=NULL;
	Newnode->right=NULL;
	return Newnode;
}

struct node* search(struct node*root ,int key)
{
	if(root==NULL)
		return root;
	else if (key==root->data)
		return root;
	else if(key<root->data)
		return search(root->left,key);
	else
		return search(root->right,key);
}

