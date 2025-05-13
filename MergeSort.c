#include<stdio.h>
void merge(int arr[],int left,int mid,int right)
{
	int i,j;
	int size1=mid-left+1;
	int size2=right-mid;
	int Left[size1],Right[size2];
	for(i=0;i<size1;i++)
	Left[i]=arr[left+i];
	for(j=0;j<size2;j++)
	Right[j]=arr[mid+1+j];
	int k=left;
	i=0;j=0;
	while(i<size1 && j<size2)
	{
		if(Left[i]<=Right[j])
		arr[k++]=Left[i++];
		else
		arr[k++]=Right[j++];
	}//while
	while(i<size1)
	arr[k++]=Left[i++];
	while(j<size2)
	arr[k++]=Right[j++];
}//merge()
void merge_sort(int arr[],int left,int right)
{
	if(left<right)
	{
		int mid=left+(right-left)/2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}//if
}//merge_sort()
int main()
{
	int i, n;
	printf("Enter number of elements:\n");
	scanf("%d", &n);
	int a[n];
	printf("Enter values:\n");
	for(i=0;i<n;i++)
	scanf("%d", &a[i]);
	merge_sort(a, 0, n-1);
	printf("Sorted List:\n");
	for(i=0;i<n;i++)
	printf("%d ", &a[i]);
	return 0;
}//main()
