#include<stdio.h>
int precedence(char ch)
{
	if(ch=='^')
	return 3;
	if(ch=='*'||ch=='/'||ch=='%')
	return 2;
	if(ch=='+'||ch=='-')
	return 1;
}
int main()
{
	int i, j=0, c=-1, k=-1, n;
	printf("Enter size\n");
	scanf("%d",&n);
	char a[n];
	printf("Enter expression\n");
	for(i=0;i<n;i++)
	scanf(" %c",&a[i]);
	char b[10],d[20];	
	char ch;
	for(i = 0; i<n; i++)
	{
		if(a[i]=='('||a[i]==')')
		j++;
		if(a[i]<48||a[i]>57)
		{
			if(k==-1)
			d[++k]=a[i];
			else if(d[k]!='(')
			{
			    if(a[i]!='(' && a[i]!=')')
				{
			    	if(precedence(a[i])>precedence(d[k]))
					d[++k]=a[i];
					else if(precedence(a[i])<=precedence(d[k]))
					{
						while(precedence(a[i])<=precedence(d[k]) && k>-1 && d[k]!='(')
						b[++c]=d[k--];
						d[++k]=a[i];
					}
		   	 	}
		    	else if(a[i]=='(')
		    	d[++k]=a[i];
		    	else
		     	{
		    		while(d[k]!='(')
		    		b[++c]=d[k--];
		    		k--;
				}
			}
			else
			d[++k]=a[i];
	    }
	    else
	    b[++c]=a[i];
	}
	for(i=k;i>=0;i--)
	b[++c]=d[i];
	for(i=0;i<n-j;i++)
	printf("%c",b[i]);
	return 0;
}
