#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co,exp;
	struct node *next;
};
struct node *head=0,*temp,*newnode;
void create_list()
{
	int ch=1;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter coefficient\n");
		scanf("%d",&newnode->co);
		printf("Enter exponent\n");
		scanf("%d",&newnode->exp);
		newnode->next=0;
		if(head==0)
		head=temp=newnode;
		else
		{
			temp->next=newnode;
			temp=newnode;
		}//else
		printf("Insert more terms? 1 or 0\n");
		scanf("%d",&ch);
	}//while
}//create_list()
void display()
{
	temp=head;
	while(temp!=0)
	{
		if(temp->co==1)
		{
			if(temp==head)
			{
				if(temp->exp==1)
				printf("x");
				else if(temp->exp==0)
				printf("%d",1);
				else
				printf("x^%d",temp->exp);
			}//if
			else
			{
				if(temp->exp==1)
				printf("+x");
				else if(temp->exp==0)
				printf("+%d",1);
				else
				printf("+x^%d",temp->exp);
			}
		}//if
		else
		{
			if(temp->co>0)
			{
				if(temp==head)
				{
					if(temp->exp==1)
					printf("%dx",temp->co);
					else if(temp->exp==0)
					printf("%d",temp->co);
		    		else
					printf("%dx^%d",temp->co,temp->exp);
				}//if
				else
				{
					if(temp->exp==1)
					printf("+%dx",temp->co);
					else if(temp->exp==0)
					printf("+%d",temp->co);
		    		else
					printf("+%dx^%d",temp->co,temp->exp);
				}//else
			}//if
			else
			{
				if(temp->exp==1)
				printf("%dx",temp->co);
				else if(temp->exp==0)
				printf("%d",temp->co);
		    	else
				printf("%dx^%d",temp->co,temp->exp);
			}//else
		}//else
		temp=temp->next;
	}//while
}//display()
int main()
{
	create_list();
	display();
	return 0;
}//main()
