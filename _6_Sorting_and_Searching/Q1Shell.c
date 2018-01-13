#include<stdio.h>
int main()
{
	int a[100],pos=0,i,value=0,n,N;
	printf("Enter the array size\n");
	scanf("%d",&n);
	N=n;
	printf("Enter the array eleemnt\n" );
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(N>0)
	{ 
		N=N/2;
		
		for(i=N;i<n;i++)
	     {
		     pos=i;
		     value=a[i];
		     while(pos>=0&&a[pos-N]>value)
		       {
			     a[pos]=a[pos-N];
			     pos=pos-N;

		        }
		     a[pos]=value;

	     }
	     for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	}
	printf("array element after sort\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}