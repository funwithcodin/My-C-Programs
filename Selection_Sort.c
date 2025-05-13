#include<stdio.h>
void SelectionSort(int A[], int n)
{
	//Sorts the elements of an array in ascending order
	int i, j, min, temp;
	for(i=0; i<n-1; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
		if(A[j]<A[min])
		min = j;
		temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}//end of i loop
}//end of SelectionSort()
void display(int A[], int n)
{
	//Prints the elements of an array
	int i;
	for(i=0; i<n; i++)
	printf("%d ", A[i]);
}//end of display()
int main()
{
	int A[] = {12, 29, 25, 8, 32, 17, 40};
	SelectionSort(A, 7);
	printf("Sorted Array: ");
	display(A, 7);
	return 0;
}//end of main()
