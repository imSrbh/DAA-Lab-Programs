#include<stdio.h>
#include<stdlib.h>

int BinSrch(int low,int high,int* arr, int key)
{
	if(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid]==key)
		{	
			printf("Found at position : ");
			return mid;
		}
		else if(arr[mid]>key)
		{
			BinSrch(low,mid-1,arr,key);
		}
		else if(arr[mid]<key)
		{
			BinSrch(mid+1,high,arr,key);
		}
	}
	else
	{
		printf("Not Found : ");
		return -1;
	}
}






int main()
{
	int len;
	int key;
	int i;
	printf("Enter the Length of the array :");
	scanf("%d",&len);
	int* arr=(int*)malloc(len*sizeof(int));
	
	printf("Enter the Array : ");
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	printf("Enter the Number you want to search : ");
	scanf("%d",&key);
	
	printf("%d\n",(BinSrch(0,len-1,arr,key)+1));
	return 0;
}
