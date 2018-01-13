#include<stdio.h>
#include<stdlib.h>
#include"quickSort.c"


void Chk(int* arr,int len)
{
	int i=0;
	int tm;
	int flag = 0;
	QuickSort(arr,0,len-1);
	for(i=0;i<len-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			printf("Duplicate Found\n");
			flag=1;
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
	printf("Enter the size of the Array : ");
	scanf("%d",&len);
	printf("Enter the Array : ");
	int* arr=(int*)malloc(len*sizeof(int));
	int i=0;
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	Chk(arr,len);
}
