#include<stdio.h>
 int mk[100],l=0;
 int min(int i,int j,int m[100][100],int *p)
 {
 	int k=i,a[k],min=9999999;
 	for(k=i;k<j;k++)
 	{
 		a[k]=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
 		if(a[k]<min)
 			{
 				min=a[k];
 				mk[l]=k+1;
 				l++;
 			}
 	}
 	return min;
 }
int main()
{
	int p[100],m[100][100],i,j,a,k;
	printf("Enter the total number of matrics\n");
	scanf("%d",&a);
	printf("Enter the instance of matrics\n");
	for(i=0;i<a;i++)
		for(j=0;j<a;j++)
			m[i][j]=0;
	for(i=0;i<a+1;i++)
		scanf("%d",&p[i]);
	for(k=0;k<a;k++)
	{
		for(i=0,j=k;i<a;i++,j++)
		{
			if(i!=j&&j<a)
			{
				m[i][j]=min(i,j,m,p);

			}

		}
	}
	printf("optimal scaler multiplication is %d an k=%d\n",m[0][a-1],mk[l-1]);
}
