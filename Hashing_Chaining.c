#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void insert(struct node *a[], int n, int v)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=v;
	newnode->next=NULL;
	int pos=v%n;
	if(a[pos]==NULL)
	a[pos]=newnode;
	else
	{
		struct node *temp=a[pos];
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=newnode;
	}//else
}//insert()
void search(struct node *a[], int n, int v)
{
	int pos=v%n;
	if(a[pos]==NULL)
	printf("%d is not present\n",v);
	else if(v==a[pos]->data)
	printf("%d is present at index %d\n",v,pos);
	else
	{
		struct node *temp=a[pos]->next;
		int flag=0;
		while(temp!=NULL)
		{
			if(temp->data==v)
			{
				printf("%d is present at index %d\n",v,pos);
				flag=1;
				break;
			}//if
			temp=temp->next;
		}//while
		if(flag==0)
		printf("%d is not present\n",v);
	}//else if
}//search()
int main()
{
	struct node *a[10];int i;
	for(i=0;i<10;i++)
	a[i]=NULL;
	int x, ch=1, ch1;
	while(ch)
	{
		printf("1. Insert\n2. Search\n");
		printf("Enter choice\n");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1: printf("Enter key\n");
					scanf("%d",&x);
					insert(a, 10, x);
					break;
			case 2: printf("Enter key to be searched\n");
					scanf("%d",&x);
					search(a, 10, x);
					break;
			default: printf("Wrong choice\n");
		}//switch
		printf("Continue? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	return 0;
}//main()
