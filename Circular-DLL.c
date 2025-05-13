#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next, *prev;
};

struct node *head=NULL, *temp, *t, *newnode;

void insert(int x)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	if(head==NULL)
	{
		head=temp=newnode;
		newnode->prev=head;
		newnode->next=head;
	}//if
	else
	{
		temp->next=newnode;
		head->prev=newnode;
		newnode->prev=temp;
		newnode->next=head;
		temp=newnode;
	}//else
}//insert()

void delete(int x)
{
	if(x==head->data)
	{
		if(head->next==head)
		head=NULL;
		else{
			head->next->prev=head->prev;
			head->prev->next=head=head->next;
		}//else
	}//if
	else
	{
		int flag=0;
		t=head->next;
		while(t!=head)
		{
			if(t->data==x)
			{
				t->prev->next=t->next;
				flag=1;
				break;
			}//if
			t=t->next;
		}//while
		if(!flag)
		printf("%d is not present in the list\n",x);
	}//else
}//delete()

void display()
{
	if(head==NULL)
	printf("List is empty\n");
	else{
		printf("Items in the list are: ");
		t=head;
		printf("%d, ",t->data);
		t=t->next;
		while(t!=head->prev)
		{
			printf("%d, ",t->data);
			t=t->next;
		}//while
		printf("%d\n",t->data);
	}//else
}//display()

int main()
{
	int ch=1, ch1, x;
	while(ch)
	{
		printf("Enter 1 for Insertion\nEnter 2 for Deletion\nEnter 3 for Display\n");
		printf("Enter choice\n");
		scanf("%d",&ch1);
		switch(ch1){
			case 1: printf("Enter item to be inserted\n");
					scanf("%d",&x);
					insert(x);
					break;
			case 2: if(head==NULL)
					printf("List is empty\n");
					else
					{
						printf("Enter item to be deleted\n");
						scanf("%d",&x);
						delete(x);
					}//else
					break;
			case 3: display();
					break;
			default: printf("Wrong Choice\n");
		}//switch
		printf("Continue? YES:1  NO:0\n");
		scanf("%d",&ch);
	}//while
	return 0;
}//main()
