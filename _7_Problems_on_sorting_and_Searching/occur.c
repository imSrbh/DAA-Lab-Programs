/*Given an array of n elements, give an algorithm for finding the element which appears
maximum number of times in the array in O(nlogn) time.*/
#include<stdio.h>
#include"quickSort.c"

int main()
{
	int a[100],i,n,pos=-1,max=0,c=0;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	printf("Enter the array elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	a[n]=9999999;

	//merge_sort(a,0,n-1);
	QuickSort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			c=c+1;
		}
		else
		{
			if(max<(c+1))
			{
				max=c+1;
				c=0;
				pos=i-1;
			}
			else
				c=0;
		}
	}

	printf("maximum occurence is %d of element %d \n",max,a[pos]);


}

