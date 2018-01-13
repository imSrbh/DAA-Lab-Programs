#include<stdio.h>

void combine(int *s,int f,int d,int k);
//divide part

void merge_sort(int *a, int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		combine(a,low,high,mid);
	}
}
// combine and conquer part
void combine(int *a,int low, int high, int mid)
{
	int i=low,j=mid+1,k=low,c[100];
	while(i<=mid&&j<=high)
	{
		if(a[i]>a[j])
		{
			c[k]=a[j];
			j++;
			k++;
		}
		else
		{
			c[k]=a[i];
			i++;
			k++;
		}
	}
	while(i<=mid)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		c[k]=a[j];
		j++;
		k++;
	}
	for(i=low;i<=high;i++)
		a[i]=c[i];
}
int main()
{
	int a[100],i,n;
	printf("Enter the array size : ");
	scanf("%d",&n);
	printf("Enter the array element : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,n-1);
	printf("Sorted elements : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
