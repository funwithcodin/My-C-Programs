#include<stdio.h>
int quicksort(int arr[],int low,int high)
{
	int i=low,j=high;
	int pivot=arr[(low+high)/2];
	while(i<=j)
	{
		while(arr[i]<pivot)
		i++;
		while(arr[j]>pivot)
		j--;
		if(i<=j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;j--;
		}//if
	}//while
	if(low<j)
	quicksort(arr,low,j);
	if(i<high)
	quicksort(arr,i,high);
	return 0;
}//quicksort()
int main()
{
	int arr[]={5,7,4,2,8};
	int j,temp,low=0,high=4;
	int k=low-1,pivot=arr[high];
	for(j=0;j<high;j++)
	{
		if(arr[j]<=pivot)
		{
			k++;
			temp=arr[j];
			arr[j]=arr[k];
			arr[k]=temp;
		}//if
	}//for
	temp=arr[k+1];
	arr[k+1]=arr[high];
	arr[high]=temp;
	int pi=k+1;
	quicksort(arr,low,pi-1);
	quicksort(arr,pi+1,high);
	printf("Sorted Array:\n");
	for(j=0;j<5;j++)
	printf("%d ",arr[j]);
	return 0;
}//main()
