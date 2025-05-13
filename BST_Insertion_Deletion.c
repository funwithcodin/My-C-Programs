#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
int a[50],i=0;
struct node *q;
struct node *root;
struct node *insert(struct node *root, int x)
{
	if(root==0)
	{
		struct node *newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=x;
		newnode->lchild=0;newnode->rchild=0;
		return newnode;
	}//if
	else if(x>root->data)
	root->rchild=insert(root->rchild,x);
	else if(x<root->data)
	root->lchild=insert(root->lchild,x);
}//insert()
void Inorder(struct node *root)
{
	if(root==0)
	return;
	Inorder(root->lchild);
	a[i++]=root->data;
	Inorder(root->rchild);
}//Inorder()
void Preorder(struct node *root)
{
	if(root==0)
	return;
	printf("%d ",root->data);
	Preorder(root->lchild);
	Preorder(root->rchild);
}//Preorder()
void Postorder(struct node *root)
{
	if(root==0)
	return;
	Postorder(root->lchild);
	Postorder(root->rchild);
	printf("%d ",root->data);
}//Postorder()
void delete(struct node *root,struct node *parent, int x)
{
	if(root==0)
	printf("%d is not present\n",x);
	else if(x==root->data)
	{
		if(root->lchild==0 && root->rchild==0)
		{
			if(root==parent)
			q=0;
			else if(root==parent->lchild)
			parent->lchild=0;
			else
			parent->rchild=0;
		}//if
		else if(root->lchild!=0 && root->rchild==0)
		{
			if(root==parent)
			q=q->lchild;
			if(root==parent->lchild)
			parent->lchild=root->lchild;
			else
			parent->rchild=root->lchild;
		}//else if
		else if(root->lchild==0 && root->rchild!=0)
		{
			if(root==parent)
			q=q->rchild;
			else if(root==parent->lchild)
			parent->lchild=root->rchild;
			else
			parent->rchild=root->rchild;
		}//else if
		else
		{
			int pos,ch,j;
			i=0;
			Inorder(q);
			for(j=0;j<i;j++)
			{
				if(a[j]==x)
				pos=j;
			}//for
			printf("1. Inorder Predecessor\n2. Inorder Successor\n");
			printf("Enter choice\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: delete(root,root,a[pos-1]);
						root->data=a[pos-1];
						break;
				case 2: delete(root,root,a[pos+1]);
						root->data=a[pos+1];
						break;
				default: printf("Wrong choice\n");
			}//switch
		}//else
	}//else if
	else if(x>root->data)
	delete(root->rchild,root,x);
	else
	delete(root->lchild,root,x);
}//delete()
int main()
{
	int ch=1,x;
	while(ch)
	{
		printf("Enter item to be inserted\n");
		scanf("%d",&x);
		root=insert(root,x);
		printf("Insert more items? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	q=root;
	i=0;
	Inorder(root);
	int j;
	printf("Inorder: ");
	for(j=0;j<i;j++)
	printf("%d ",a[j]);
	printf("\nPreorder: ");
	Preorder(root);
	printf("\nPostorder: ");
	Postorder(root);
	ch=1;
	while(ch)
	{
		if(q==0)
		{
			printf("Tree is empty\n");
			break;
		}//if
		else
		{
			printf("\nEnter item to be deleted\n");
			scanf("%d",&x);
			delete(root,root,x);
			printf("Delete more items? 1 or 0\n");
			scanf("%d",&ch);
		}//else
	}//while
	i=0;
	Inorder(q);
	printf("Inorder: ");
	for(j=0;j<i;j++)
	printf("%d ",a[j]);
	printf("\nPreorder: ");
	Preorder(q);
	printf("\nPostorder: ");
	Postorder(q);
	return 0;
}//main()
