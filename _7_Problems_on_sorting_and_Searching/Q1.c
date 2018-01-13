#include<stdio.h>
#include<stdlib.h>


int partision(int * arr,int low,int high)
{
	int i = low+1;
	int j = high;
	int tmp;
	int pivot = arr[low];
	while(i<=j)
	{
		while(arr[i]<=pivot)
			i++;
		while(arr[j]>pivot)
			j--;
		if(i<j)
		{
			tmp = arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
		}
	}
	tmp = arr[j];
	arr[j] = arr[low];
	arr[low] = tmp;
	return j;
}

void QuickSort(int * arr, int low,int high)
{
	if(low<high)
	{
		int k = partision(arr,low,high);
		QuickSort(arr,low,k-1);
		QuickSort(arr,k+1,high);
	}
}

int BinSrch(int low,int high,int* arr, int key)
{
	if(low<=high)
	{
		int mid = (low+high)/2;
		if(arr[mid]==key)
		{
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
		return -1;
	}
}


void Chk(int* arr,int len,int K)
{
	int i=0;
	int tm;
	int flag = 0;
	QuickSort(arr,0,len-1);
	for(i=0;i<len;i++)
	{
		tm = BinSrch(0,len-1,arr,K-arr[i]);
		if(i!=tm && tm!=-1)
		{
			printf("Found\n");
			flag =1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Not Found\n");
	}
	return;
}


int main()
{
	int len;
	int K;
	printf("Enter the size of the Array : ");
	scanf("%d",&len);
	printf("Enter the Array : ");
	int* arr=(int*)malloc(len*sizeof(int));
	int i=0;
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the K element : ");
	scanf("%d",&K);
	Chk(arr,len,K);
}
