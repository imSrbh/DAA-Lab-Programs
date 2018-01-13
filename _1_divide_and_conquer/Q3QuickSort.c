#include<stdio.h>

int len;

void printArray(int *arr,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d, ",arr[i]);
	}
	printf("\n");
}


int partision(int *arr,int low,int high)
{
	int pe = arr[low];
	printf("Selected pivot : %d, high = %d, low = %d ",pe,high,low);
	int i = low+1;
	int j = high;
	while(i<=j)
	{
		while(arr[i]<=pe && i<=high)
		{
			i++;
		}
		while(arr[j]>pe && j>=low)
		{
			j--;
		}
		printf("i = %d, j = %d\n",i,j);
		if(i<j)
		{
			int tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++;
			j--;
		}
	}
	printf("\n");
	if(j>low)
	{
		arr[low]=arr[j];
		arr[j]=pe;
	}
	printf("After setting pivot :");
	printArray(arr,len);
	return j;	
}

void QuickSort(int *arr,int low,int high)
{
	if(low<high)
	{
		int pivot = partision(arr,low,high);
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}


int main()
{
	
	int i;
	printf("Enter the Length of the array : ");
	scanf("%d",&len);
	int arr[10];
	
	printf("Enter the Array : ");
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	QuickSort(arr,0,len-1);
	printf("\nFinal Array is : ");
	printArray(arr,len);
	return 0;
}


