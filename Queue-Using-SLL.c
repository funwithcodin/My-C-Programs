#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=0,*rear,*front,*newnode;
void Enqueue()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data to be pushed\n");
	scanf("%d",&newnode->data);
	if(head==0)
	head=rear=newnode;
	else
	{
		rear->next=newnode;
		rear=newnode;
	}//else
	newnode->next=0;
}//Push()
void Dequeue()
{
	if(head==0)
	printf("Underflow\n");
	else
	{ 
		front=head;
		if(front->next==0)
		head=0;
		else
		head=front->next;
	}//else
}//Pop()
int main()
{
	int ch=1,ch1;
	while(ch)
	{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("Enter choice\n");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1: Enqueue();
			        break;
			case 2: Dequeue();
			        break;
			default: printf("Wrong choice\n");
		}//switch
		printf("Continue? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	if(head!=0)
	{
		front=head;
		printf("Items in the queue are:\n");
		while(front!=0)
		{
			printf("%d ",front->data);
			front=front->next;
		}//while
	}//if
	else
	printf("Queue is empty");
	return 0;
}//main()
