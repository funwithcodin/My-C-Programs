#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co,exp;
	struct node *next;
};
struct node *head1=0,*head2=0,*head_q=0,*head_r=0,*p1,*p2,*q,*r,*temp,*head_t=0,*newnode;
void createnode_quo(int x, int y)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=0;
	newnode->co=x;
	newnode->exp=y;
	if(head_q==0)
	head_q=q=newnode;
	else
	{
		q->next=newnode;
		q=newnode;
	}//else
}//createnode_quo()
void createnode_rem(int x, int y)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=0;
	newnode->co=x;
	newnode->exp=y;
	if(head_r==0)
	head_r=r=newnode;
	else
	{
		r->next=newnode;
		r=newnode;
	}//else
}//createnode_rem()
void createnode_temp(int x,int y)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=0;
	newnode->co=x;
	newnode->exp=y;
	if(head_t==0)
	head_t=temp=newnode;
	else
	{
		temp->next=newnode;
		temp=newnode;
	}//else
}//createnode_temp()
void delete_from_front()
{
	r=head_r;
	head_r=r->next;
}//delete_from_front()
void delete_temp()
{
	temp=head_t;
	while(temp!=0)
	{
		head_t=temp->next;
		temp=temp->next;
	}//while
}//delete_temp()
void createPol1()
{
	int ch=1;
	printf("Polynomial 1 (Dividend):\n");
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
}//createPol1()
void createPol2()
{
	int ch=1;
	printf("Polynomial 2 (Divisor):\n");
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
}//createPol2()
void divide()
{
	p1=head1;p2=head2;
	if(p1->exp<p2->exp)
	{
		createnode_quo(0,0);
		while(p1!=0)
		{
			createnode_rem(p1->co,p1->exp);
			p1=p1->next;
		}//while
	}//if
	else
	{
		int f,d;
		if(head_r==0)
		{
			f=p1->co/p2->co;
			d=p1->exp-p2->exp;
			createnode_quo(f,d);
			p1=p1->next;
			p2=p2->next;
			while(p2!=0)
			{
				createnode_temp(p2->co*f,p2->exp+d);
				p2=p2->next;
			}//while
			temp=head_t;
			while(p1!=0 && temp!=0)
			{
				if(p1->exp<temp->exp)
				{
				   createnode_rem(-temp->co,temp->exp);
				   temp=temp->next;
				}//if
				else if(p1->exp>temp->exp)
				{
					createnode_rem(p1->co,p1->exp);
					p1=p1->next;
				}//else if
				else
				{
					createnode_rem(p1->co-temp->co,p1->exp);
					p1=p1->next;temp=temp->next;
				}//else
			}//while
			while(p1!=0)
			{
				createnode_rem(p1->co,p1->exp);
				p1=p1->next;
			}//while
			while(temp!=0)
			{
				createnode_rem(-temp->co,temp->exp);
				temp=temp->next;
			}//while
			delete_temp();
		}//if
		p2=head2;r=head_r;
		while(p2->exp<=r->exp)
		{
			f=r->co/p2->co;
			d=r->exp-p2->exp;
			createnode_quo(f,d);
			p2=p2->next;r=r->next;
			while(p2!=0)
			{
				createnode_temp(p2->co*f,p2->exp+d);
				p2=p2->next;
			}//while
			temp=head_t;
			while(r!=0 && temp!=0)
			{
				if(r->exp<temp->exp)
				{
				   createnode_rem(-temp->co,temp->exp);
				   temp=temp->next;
				}//if
				else if(r->exp>temp->exp)
				{
					createnode_rem(r->co,r->exp);
					r=r->next;
				}//else if
				else
				{
					createnode_rem(r->co-temp->co,r->exp);
					r=r->next;temp=temp->next;
				}//else
			}//while
			while(r!=0)
			{
				createnode_rem(r->co,r->exp);
				r=r->next;
			}//while
			while(temp!=0)
			{
				createnode_rem(-temp->co,temp->exp);
				temp=temp->next;
			}//while
			delete_temp();
			p2=head2;
			while(p2!=0)
			{
				delete_from_front();
				p2=p2->next;
			}//while
			p2=head2;
			r=head_r;
		}//while
	}//else
}//divide()
int main()
{
	createPol1();
	createPol2();
	divide();
	q=head_q;r=head_r;
	printf("Quotient:\n");
	if(q->co==0)
	printf("%d\n",0);
	else
	{
		while(q!=0)
		{
			if(q==head_q)
			{
				if(q->co==1)
				{
					if(q->exp==0)
					printf("1");
					else
					printf("x^%d",q->exp);
				}//if
				else
				{
					if(q->exp==0)
					printf("%d",q->co);
					else
					printf("%dx^%d",q->co,q->exp);
				}//else
			}//if
			else
			{
				if(q->co>0)
				{
					if(q->co==1)
					{
						if(q->exp==0)
						printf("+1");
						else
						printf("+x^%d",q->exp);
					}//if
					else
					{
						if(q->exp==0)
						printf("+%d",q->co);
						else
						printf("+%dx^%d",q->co,q->exp);
					}//else
				}//if
				else if(q->co<0)
				{
					if(q->co==-1)
					{
						if(q->exp==0)
						printf("-1");
						else
						printf("-x^%d",q->exp);
					}//if
					else
					{
						if(q->exp==0)
						printf("%d",q->co);
						else
						printf("%dx^%d",q->co,q->exp);
					}//else
				}//else if
			}//else
			q=q->next;
		}//while
	}//else
	printf("Remainder:\n");
	while(r!=0)
	{
		if(r==head_r)
		{
			if(r->co==1)
			{
				if(r->exp==0)
				printf("1");
				else
				printf("x^%d",r->exp);
			}//if
			else
			{
				if(r->exp==0)
				printf("%d",r->co);
				else
				printf("%dx^%d",r->co,r->exp);
			}//else
		}//if
		else
		{
			if(r->co>0)
			{
				if(r->co==1)
				{
					if(r->exp==0)
					printf("+1");
					else
					printf("+x^%d",r->exp);
				}//if
				else
				{
					if(r->exp==0)
					printf("+%d",r->co);
					else
					printf("+%dx^%d",r->co,r->exp);
				}//else
			}//if
			else if(r->co<0)
			{
				if(r->co==-1)
				{
					if(r->exp==0)
					printf("-1");
					else
					printf("-x^%d",r->exp);
				}//if
				else
				{
					if(r->exp==0)
					printf("%d",r->co);
					else
					printf("%dx^%d",r->co,r->exp);
				}//else
			}//else if
		}//else
		r=r->next;
	}//while
	return 0;
}//main()
