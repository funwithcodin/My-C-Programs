#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int main()
{
	struct node *head1=0,*head2=0,*temp,*newnode;
	int ch=1;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter data\n");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head1==0)
		head1=temp=newnode;
		else
		{
			temp->next=newnode;
			temp=newnode;
		}//else
		printf("Continue? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	printf("Original data\n");
	temp=head1;
	while(temp!=0)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}//while
	printf("\nData in reverse:\n");
	temp=head1;
	while(temp!=0)
	{
	    newnode=(struct node*)malloc(sizeof(struct node));
	    newnode->data=temp->data;
	    if(head2==0)
	    {
	    	head2=newnode;
	    	newnode->next=0;
	    }//if
	    else
	    {
	    	newnode->next=head2;
	    	head2=newnode;
		}//else
	    temp=temp->next;
	}//while
	temp=head2;
	while(temp!=0)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}//while
	return 0;
}//main()
