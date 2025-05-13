#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
struct node* insert(struct node *t, int item)
{
	if(t==NULL)
	{
		struct node *newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=item;
		newnode->lchild=NULL;
		newnode->rchild=NULL;
		return newnode;
	}//if
	else if(item<t->data)
	t->lchild=insert(t->lchild,item);
	else
	t->rchild=insert(t->rchild,item);
}//insert()
void Inorder(struct node *t)
{
	if(t==NULL)
	return;
	Inorder(t->lchild);
	printf("%d ",t->data);
	Inorder(t->rchild);
}//Inorder()
void Preorder(struct node *t)
{
	if(t==NULL)
	return;
	printf("%d ",t->data);
	Preorder(t->lchild);
	Preorder(t->rchild);
}//Preorder()
void Postorder(struct node *t)
{
	if(t==NULL)
	return;
	Postorder(t->lchild);
	Postorder(t->rchild);
	printf("%d ",t->data);
}//Postorder()
int main()
{
	struct node *root;
	root=NULL;
	int ch=1,x;
	while(ch)
	{
		printf("Enter item to be entered:\n");
		scanf("%d",&x);
		root=insert(root,x);
		printf("Continue? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	printf("Inorder: ");
	Inorder(root);
	printf("\nPreorder: ");
	Preorder(root);
	printf("\nPostorder: ");
	Postorder(root);
	return 0;
}//main()
