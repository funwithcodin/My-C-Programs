#include<stdio.h>
#include<stdlib.h>
struct node
{
	int co,exp;
	struct node *next;
};
struct node *head1=0,*head2=0,*head3=0,*p1,*p2,*p3,*newnode;
void createNode_p3(int x, int y)
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
}//createNode_p3()
void createPol1()
{
	int ch=1;
	printf("Polynomial 1:\n");
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
	printf("Polynomial 2:\n");
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
void mulPol12()
{
	p1=head1;
	while(p1!=0)
	{
		p2=head2;
		while(p2!=0)
		{
			createNode_p3(p1->co*p2->co,p1->exp+p2->exp);
			p2=p2->next;
		}//while
		p1=p1->next;
	}//while
	p3=head3;
	struct node *t1=p3,*t2=p3;
	int c1=0,c2=0;
	while(p3!=0)
	{
		t1=p3->next;
		c1++;
		c2=0;
		while(t1!=0)
		{
			c2++;
			if(p3->exp==t1->exp)
			{
				p3->co=p3->co+t1->co;
				int i=1;
				t2=head3;
				while(c1+c2>(i+1))
				{
					t2=t2->next;
					i++;
				}//while
				t2->next=t2->next->next;
				c2--;
			}//if
			t1=t1->next;
		}//while
		p3=p3->next;
	}//while
}//mulPol12()
int main()
{
	createPol1();
	createPol2();
	mulPol12();
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
