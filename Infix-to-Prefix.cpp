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
	int pos=0;
	printf("Enter size\n");
	scanf("%d",&n);
	char a[n], r[n];
	printf("Enter expression\n");
	for(i=0;i<n;i++)
	scanf(" %c",&a[i]);
	for(i=n-1;i>=0;i--)
	r[i]=a[pos++];
	char b[10],d[20];	
	char ch;
	for(i=0; i<n; i++)
	{
		if(r[i]==')'||r[i]=='(')
		j++;
		if(r[i]<48||r[i]>57)
		{
			if(k==-1)
			d[++k]=r[i];
			else if(d[k]!=')')
			{
			    if(r[i]!=')' && r[i]!='(')
				{
			    	if(precedence(r[i])>precedence(d[k]))
					d[++k]=r[i];
					else if(precedence(a[i])<=precedence(d[k]))
					{
						while(precedence(a[i])<=precedence(d[k]) && k>-1 && d[k]!='(')
						b[++c]=d[k--];
						d[++k]=a[i];
					}
		   	 	}
		    	else if(r[i]==')')
		    	d[++k]=r[i];
		    	else
		     	{
		    		while(d[k]!=')')
		    		b[++c]=d[k--];
		    		k--;
				}
			}
			else
			d[++k]=r[i];
	    }
	    else
	    b[++c]=r[i];
	}
	for(i=k;i>=0;i--)
	b[++c]=d[i];
	for(i=n-j;i>=0;i--)
	printf("%c",b[i]);
	return 0;
}
