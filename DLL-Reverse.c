#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=0,*temp,*newnode;
int main()
{
	int ch=1;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data\n");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==0)
		{
			head=temp=newnode;
			newnode->prev=0;
		}//if
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}//else
		printf("Continue? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	printf("Original List:\n");
	temp=head;
	while(temp->next!=0)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}//while
	printf("%d\n",temp->data);
	printf("Reversed list:\n");
	while(temp!=0)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}//while
	return 0;
}//main()
