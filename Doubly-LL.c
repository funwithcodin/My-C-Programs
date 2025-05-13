#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=0,*temp,*newnode;
void createlist()
{
	int ch=1;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data\n");
		scanf("%d",&newnode->data);
		newnode->next=0;
		newnode->prev=0;
		if(head==0)
		head=temp=newnode;
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}//else
		printf("Enter more data? 1 or 0\n");
		scanf("%d",&ch);
	}//while
}//createlist()
void insert(int x)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	int ch,pos;
	printf("Your choices are:\n");
	printf("1. Insert at the beginning\n2.Insert at the end\n3.Insert at the middle\n");
	printf("Enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: newnode->next=head;
		        newnode->prev=0;
		        head=newnode;
		        break;
		case 2: temp=head;
				while(temp->next!=0)
				temp=temp->next;
				temp->next=newnode;
				newnode->prev=temp;
				newnode->next=0;
				break;
		case 3: printf("Enter position at which item is to be inserted\n");
				scanf("%d",&pos);
				int i=1;temp=head;
				while(pos>i+1)
				{
					temp=temp->next;
					i++;
				}//while
				newnode->next=temp->next;
				temp->next=newnode;
				newnode->prev=temp;
				break;
		default: printf("Wrong choice\n");
	}//switch
}//insert()
void delete()
{
	if(head==0)
	printf("List is empty\n");
	else
	{
		int ch,pos;temp=head;
		printf("Your choices are:\n");
		printf("1. Deletion from the beginning\n2.Deletion from the end\n3.Deletion from the middle\n");
		printf("Enter choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(temp->next==0)
					head=0;
					else
					{
						head=temp->next;
						temp->next->prev=0;
					}//else
					free(temp);
					break;
			case 2: if(temp->next==0)
					{
						head=0;
						free(temp);
					}//if
					else
					{
						while(temp->next->next!=0)
						temp=temp->next;
						free(temp->next);
						temp->next=0;
					}//else
					break;
			case 3: printf("Enter postion from which item is to be deleted\n");
					scanf("%d",&pos);
					int i=1;
					while(pos>i+1)
					{
						temp=temp->next;
						i++;
					}//while
					temp->next=temp->next->next;
					temp->next->next->prev=temp;
					break;
			default: printf("Wrong choice\n");
		}//switch
	}//else
}//delete()
int main()
{
	printf("CREATING LIST:\n");
	createlist();
	temp=head;
	printf("Original list:\n");
	while(temp!=0)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}//while
	int ch=1,ch1,val;
	while(ch)
	{
		printf("\nDo you want to Insert or Delete?\n");
		printf("1. Insert\n2.Delete\n");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1: printf("Enter item to be inserted\n");
					scanf("%d",&val);
					insert(val);
					break;
			case 2: delete();
					break;
			default: printf("Wrong choice\n");
		}//switch
		printf("Continue operating? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	printf("New list:\n");
	if(head==0)
	printf("List is empty\n");
	else
	{
		temp=head;
		while(temp!=0)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}//while
	}//else
	return 0;
}//main
