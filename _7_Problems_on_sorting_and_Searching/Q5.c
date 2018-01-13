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

int Chk(int * arr,int len)
{
	QuickSort(arr,0,len-1);
	int i=0;
	int j=0;
	int Count_Distinct = 1;
	for(i=0;i<len;i++)
	{
		if(i<len-1)
		{
			if(arr[i]!=arr[i+1])
				Count_Distinct++;
		}
	}
		
	//printf("Count_Distict = %d\n",Count_Distinct);
	int at[Count_Distinct][2];
	for(i=0;i<Count_Distinct;i++)
	{
		at[i][0]=0;
	}
	for(i=0,j=0;i<len;i++)
	{
		at[j][1]=arr[i];
		at[j][0]++;
		if(i<len-1 && arr[i]!=arr[i+1])
			j++;
	}
	int maxfreq = at[0][0];
	int maxfreqof = at[0][1];
	for(i=0;i<Count_Distinct;i++)
	{
		if(at[i][0]>maxfreq)
		{
			maxfreq=at[i][0];
			maxfreqof = at[i][1];
		}
	}
	//printf("Max Freq is : %d , of %d\n",maxfreq,maxfreqof);
	return maxfreqof;
}

int main()
{
	int len;
	printf("Enter the size of the Array : ");
	scanf("%d",&len);
	printf("Enter the Array : ");
	int* arr=(int*)malloc(len*sizeof(int));
	int i=0;
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	};
	int answer = Chk(arr,len);
	printf("The Element '%d' occurs maximum number of times in the array\n",answer);
}
