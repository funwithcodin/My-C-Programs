#include<stdio.h>
#include<math.h>
int n;
void max_heapify(int A[], int i)
{
	int l = 2*i;
	int r = 2*i+1;
	int largest;
	if(l<=n && A[l-1]>A[i-1])
	largest = l;
	else
	largest = i;
	if(r<=n && A[r-1]>A[largest-1])
	largest = r;
	if(largest!=i)
	{
		int t=A[i-1];
		A[i-1]=A[largest-1];
		A[largest-1]=t;
		max_heapify(A, largest);
	}//if
}//max_heapify()
void Build_max_heap(int A[])
{
	int i;
	for(i=(int)floor(n/2);i>=1;i--)
	max_heapify(A, i);
}//Build_max_heap()
void Heapsort(int A[])
{
	Build_max_heap(A);
	int i;
	for(i=n;i>=2;i--)
	{
		int t=A[0];
		A[0]=A[i-1];
		A[i-1]=t;
		n--;
		max_heapify(A, 1);
	}//for
}//Heapsort()
int main()
{
	printf("Enter size of the heap\n");
	scanf("%d",&n);
	int A[n];
	int i, copy=n;
	printf("Enter items\n");
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	Heapsort(A);
	printf("Sorted Heap:\n");
	for(i=0;i<copy;i++)
	printf("%d ",A[i]);
	return 0;
}//main()
