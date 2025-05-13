#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=0,*top,*newnode;
void Push()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to be pushed\n");
	scanf("%d",&newnode->data);
	if(head==0)
	{
		head=newnode;
		newnode->next=0;
	}//if
	else
	{
		newnode->next=head;
		head=newnode;
	}//else
}//Push()
void Pop()
{
	if(head==0)
	printf("Underflow\n");
	else 
	{
		top=head;
		if(top->next==0)
		head=0;
		else
		head=top->next;
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
			case 1: Push();
			        break;
			case 2: Pop();
			        break;
			default: printf("Wrong choice\n");
		}//switch
		printf("Continue? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	if(head!=0)
	{
		top=head;
		printf("Items in the stack are:\n");
		while(top!=0)
		{
			printf("%d ",top->data);
			top=top->next;
		}//while
	}//if
	else
	printf("Stack is empty");
	return 0;
}//main()
