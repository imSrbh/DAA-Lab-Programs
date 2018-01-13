#include<stdio.h>

void printArray(int *arr, int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d, ",arr[i]);
	}
	printf("\n");
}

void selectionSort(int *arr,int len)
{
	for(int i=-1;i<len;i++)
	{
		int min=arr[i+1];
		int minindex = i+1;
		for(int j=i+1;j<len;j++)
		{
			if(min>arr[j])
			{
				minindex=j;
				min=arr[j];
			}
		}
		if(minindex!=i+1)
		{
			int tmp = arr[minindex];
			arr[minindex]=arr[i+1];
			arr[i+1]=tmp;
		}
		printArray(arr,len);
	}
}

int main()
{
	int len;
	printf("Enter the length of Array : ");
	scanf("%d",&len);
	int arr[10];
	printf("Enter the Array : ");
	for(int i=0;i<len;i++)
	{	
		scanf("%d",&arr[i]);
	}
	selectionSort(arr,len);
	printf("The sorted Array is : ");
	printArray(arr,len);
}
