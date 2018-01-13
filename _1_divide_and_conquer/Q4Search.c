#include<stdio.h>
#include<stdlib.h>

int Srch(int low, int high,int*arr)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==mid)
		{
			printf("Found ");
			return mid;
		}
		else if(arr[mid]>mid)
		{
			Srch(low,mid-1,arr);
		}
		else if(arr[mid]<mid)
		{
			Srch(mid+1,high,arr);
		}
	}
	else
	{
		printf("Not Found ");
		return -1;
	}
}
		


int main()
{
	int len;
	int i;
	printf("Enter the Length of the array : ");
	scanf("%d",&len);
	int* arr=(int*)malloc(len*sizeof(int));
	
	printf("Enter the Array : ");
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("%d\n",Srch(0,len-1,arr));
	return 0;
}
