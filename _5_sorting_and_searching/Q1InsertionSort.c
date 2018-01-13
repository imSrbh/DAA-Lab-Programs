#include<stdio.h>

void printArray(int *arr, int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d, ",arr[i]);
	}
	printf("\n");
}

void insertionSort(int *arr, int len)
{
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<=i;j++)	
		{
			if(arr[i]<arr[j])
			{
				int tmp = arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
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
	insertionSort(arr,len);
	printf("The sorted Array is : ");
	printArray(arr,len);
}
