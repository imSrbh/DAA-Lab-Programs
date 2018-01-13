#include<stdio.h>
#include<stdlib.h>

int Srch(int * arr,int len)
{
	int i,j,flag=0;
	for(i=0;i<len;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(arr[i]==arr[j])
			{
				flag = 1;
				return arr[i];
			}
		}
	}
	if(flag==0)
		return -1;
}




int main()
{
	int len;
	int i;
	int rec;
	printf("Enter the Length of the array :");
	scanf("%d",&len);
	int* arr=(int*)malloc(len*sizeof(int));
	
	printf("Enter the Array : ");
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	rec = Srch(arr,len);
	if(rec!=-1)
		printf("first repeated : %d\n",rec);
	else
		printf("No repeated Element Found.\n");
	return 0;
}	
