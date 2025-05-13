#include<stdio.h>
void insert(int a[], int n, int x)
{
	int pos=x%n, prob=0;
	if(a[pos]==-1)
	a[pos]=x;
	else
	{
		int i=(pos+1)%n, c=2;
		while(1)
		{
			prob++;
			if(a[i]==-1)
			{
				a[i]=x;
				break;
			}//if
			i=(pos+c*c)%n;
			c++;
		}//while
	}//else
	printf("Number of probes: %d\n",prob);
}//insert()
void find(int a[], int n, int x)
{
	int pos=x%n;
	if(a[pos]==x)
	{
		printf("%d is present at index %d\n",x,pos);
		printf("Number of probes: 0\n");
	}//if
	else
	{
		int b[n], j;
		for(j=0;j<n;j++)
		b[j]=0;
		int i=(pos+1)%n, flag=0, c=2;
		while(1)
		{
			if(a[i]==x)
			{
				flag=1;
				printf("%d is present at index %d\n",x,i);
				printf("Number of probes: ");
				int s=0;
				for(j=0;j<n;j++)
				s=s+b[j];
				printf("%d\n",s+1);
				break;
			}//if
			if(empty(b, n)==0)
			break;
			b[i]++;
			i=(pos+c*c)%n;
			c++;
		}//while
		if(flag==0)
		printf("%d is not present\n",x);
	}//else
}//find()
int capacity(int a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==-1)
		{
			return 1;
			break;
		}//if
	}
	return 0;
}//capacity()
int empty(int b[], int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(b[i]==0)
		{
			return 1;
			break;
		}//if
	}//for
	return 0;
}//empty()
int main()
{
	int n, x;
	printf("Enter size of the hash table\n");
	scanf("%d",&n);
	int ch=1, ch1, a[n];
	int i;
	for(i=0;i<n;i++)
	a[i]=-1;
	while(ch)
	{
		printf("1. Insert\n2. Find\n");
		printf("Enter choice\n");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1: if(capacity(a, n)==1)
					{
						printf("Enter item to be inserted\n");
						scanf("%d",&x);
						insert(a, n, x);
					}//if
					else
					printf("No more space\n");
					break;
			case 2: printf("Enter item to be found\n");
					scanf("%d",&x);
					find(a, n ,x);
					break;
			default: printf("Wrong choice\n");
		}//switch
		printf("Continue? 1 or 0\n");
		scanf("%d",&ch);
	}//while
	return 0;
}//main()
