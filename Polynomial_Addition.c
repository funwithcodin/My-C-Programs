#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co, exp;
	struct node *next;
};
struct node *head1=0,*head2=0,*head3=0,*p1,*p2,*p3,*newnode;
void createNode(int x, int y)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=0;
	newnode->co=x;
	newnode->exp=y;
	if(head3==0)
	head3=p3=newnode;
	else
	{
		p3->next=newnode;
		p3=newnode;
	}//else
}//createNode()
void create_Pol1()
{
	printf("Polynomial 1:\n");
	int ch=1;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter coefficient of x\n");
		scanf("%d",&newnode->co);
		printf("Enter exponent of x\n");
		scanf("%d",&newnode->exp);
		newnode->next=0;
		if(head1==0)
		head1=p1=newnode;
		else
		{
			p1->next=newnode;
		    p1=newnode;
		}//else
		printf("Enter more terms? 1 or 0\n");
		scanf("%d",&ch);
	}//while
}//create_Pol1()
void create_Pol2()
{
	printf("Polynomial 2:\n");
	int ch=1;
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter coefficient of x\n");
		scanf("%d",&newnode->co);
		printf("Enter exponent of x\n");
		scanf("%d",&newnode->exp);
		newnode->next=0;
		if(head2==0)
		head2=p2=newnode;
		else
		{
			p2->next=newnode;
		    p2=newnode;
		}//else
		printf("Enter more terms? 1 or 0\n");
		scanf("%d",&ch);
	}//while
}//create_Pol2()
void add_Pol12()
{
	p1=head1,p2=head2;
	while(p1!=0 && p2!=0)
	{
		if(p1->exp>p2->exp)
		{
			createNode(p1->co,p1->exp);
			p1=p1->next;
		}//if
		else if(p1->exp<p2->exp)
		{
			createNode(p2->co,p2->exp);
			p2=p2->next;
		}//else if
		else
		{
			createNode(p1->co+p2->co,p1->exp);
			p1=p1->next;
			p2=p2->next;
		}//if	
	}//while
	while(p1!=0)
	{
		createNode(p1->co,p1->exp);
		p1=p1->next;
	}//while
	while(p2!=0)
	{
		createNode(p2->co,p2->exp);
		p2=p2->next;
	}//while
}//add_Pol12()
int main()
{
	create_Pol1();
	create_Pol2();
	add_Pol12();
	p3=head3;
	printf("Resultant Polynomial:\n");
	while(p3!=0)
	{
		if(p3==head3)
		{
			if(p3->co==1)
			{
				if(p3->exp==0)
				printf("1");
				else
				printf("x^%d",p3->exp);
			}//if
			else
			{
				if(p3->exp==0)
				printf("%d",p3->co);
				else
				printf("%dx^%d",p3->co,p3->exp);
			}//else
		}//if
		else
		{
			if(p3->co>0)
			{
				if(p3->co==1)
				{
					if(p3->exp==0)
					printf("+1");
					else
					printf("+x^%d",p3->exp);
				}//if
				else
				{
					if(p3->exp==0)
					printf("+%d",p3->co);
					else
					printf("+%dx^%d",p3->co,p3->exp);
				}//else
			}//if
			else if(p3->co<0)
			{
				if(p3->co==-1)
				{
					if(p3->exp==0)
					printf("-1");
					else
					printf("-x^%d",p3->exp);
				}//if
				else
				{
					if(p3->exp==0)
					printf("%d",p3->co);
					else
					printf("%dx^%d",p3->co,p3->exp);
				}//else
			}//else if
		}//else
		p3=p3->next;
	}//while
	return 0;
}//main()
