#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node* createnode()
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	int x;
	printf("Enter data (-1 for no data)\n");
	scanf("%d",&x);
	if(x==-1)
	return 0;
	newnode->data=x;
	printf("Enter left child of %d\n",x);
	newnode->left=createnode();
	printf("Enter right child of %d\n",x);
	newnode->right=createnode();
	return newnode;
}//createnode()
void Inorder(struct node *root)
{
	if(root==0)
	return;
	Inorder(root->left);
	printf("%d ",root->data);
	Inorder(root->right);
}//Inorder()
void Preorder(struct node *root)
{
	if(root==0)
	return;
	printf("%d ",root->data);
	Preorder(root->left);
	Preorder(root->right);
}//Preorder()
void Postorder(struct node *root)
{
	if(root==0)
	return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ",root->data);
}//Postorder()
int main()
{
	struct node *root=0;
	root=createnode();
	printf("Inorder: ");
	Inorder(root);
	printf("\nPreorder: ");
	Preorder(root);
	printf("\nPostorder: ");
	Postorder(root);
	return 0;
}//main()
