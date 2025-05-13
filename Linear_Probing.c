#include<stdio.h>
void insert(int a[], int n, int v)
{
	int pos=v%n, prob=0;
	if(a[pos]==-1)
	a[pos]=v;
	else
	{
		int i;
		for(i=(pos+1)%n; i!=pos; i=(i+1)%n)
		{
			prob++;
			if(a[i]==-1)
			{
				a[i]=v;
				break;
			}//if
		}//for
	}//else
	printf("Number of probes: %d\n", prob);
}//insert()
void search(int a[], int n, int v)
{
	int pos=v%n, prob=0;
	if(a[pos]==v)
	{
		printf("%d is at index %d\n",v,pos);
		printf("Number of probes: 0\n");
	}//if
	else
	{
		int i, flag=0;
		for(i=(pos+1)%n; i!=pos; i=(i+1)%n)
		{
			prob++;
			if(a[i]==v)
			{
				flag=1;
				printf("%d is at index %d\n",v,i);
				printf("Number of probes: %d\n", prob);
				break;
			}//if
		}//for
		if(flag==0)
		printf("%d is not present\n",v);
	}//else
}//search()
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
int main()
{
	int a[10], i;
	for(i=0; i<10; i++)
	a[i]=-1;
	int x, ch=1, ch1;
	while(ch)
	{
		printf("1. Insert\n2. Search\n");
		printf("Enter choice\n");
		scanf("%d",&ch1);
		switch(ch1)
		{
			case 1: if(capacity(a, 10)==1)
					{
						printf("Enter key to be inserted\n");
						scanf("%d",&x);
						insert(a, 10, x);
					}//if
					else
					printf("No more space\n");
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
