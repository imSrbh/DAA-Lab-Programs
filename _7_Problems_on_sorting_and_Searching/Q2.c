#include<stdio.h>
#include"quickSort.c"

int main()
{
	int a[100],i,k,j=0,n;
	printf("Enter the array size : ");
	scanf("%d",&n);
	printf("Enter Array : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter k : ");
	scanf("%d",&k);
	//merge_sort(a,0,n-1);
	QuickSort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		//j=sum(a,k-a[i],i+1,n-1);
		int sum=k-a[i];
		int low=i+1;
		int high=n-1;
		while(low<high)
	      {
		       if(a[low]+a[high]==sum)
			       {
				      printf("Elements are Found\n");
				      j = 1;
				      return 0;
			        }
		         else if(a[low]+a[high]>sum)
			          high--;
		         else 
			          low++;
	      }
		
	}

	if(j==0)
		printf("Combination Not Found	\n");
	return 0;
}
