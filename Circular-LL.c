#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
int main()
{
	struct node *head=0, *temp, *newnode;
	int ch=1;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter item\n");
		scanf("%d",&newnode->data);
		if(head==0)
		head=temp=newnode;
		else
		{
			temp->next=newnode;
			temp=newnode;
			newnode->next=head;
		}//else
		printf("Continue? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	ch=1;
	printf("Printing items:\n");
	while(ch)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
		printf("Continue? 1 or 0\n");
		scanf("%d",&ch);
	}//while
}
