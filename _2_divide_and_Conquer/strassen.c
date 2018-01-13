#include<stdio.h>

int main()
{
	//int first[4][4],secound[4][4],result[4][4],i,j,i1,j1;
	int i,j;
	int a[2][2],b[2][2],c[2][2];
	int A,B,C,D,E,F,G;
	int cnt=0;
	
	printf("Enter first matrix : \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Enter secound matrix : \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	
	printf("\n The First Matrix is\n");
	for(i=0;i<2;i++)
	{
		printf("\n");
		for(j=0;j<2;j++)
		{
			printf("%d, ",a[i][j]);
		}
	}
	
	printf("\n The Secound Matrix is\n");
	for(i=0;i<2;i++)
	{
		printf("\n");
		for(j=0;j<2;j++)
		{
			printf("%d, ",b[i][j]);
		}
	}	  
	printf("\n");  
	A=(a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
  	B= (a[1][0] + a[1][1]) * b[0][0];
  	C= a[0][0] * (b[0][1] - b[1][1]);
  	D= a[1][1] * (b[1][0] - b[0][0]);
  	E= (a[0][0] + a[0][1]) * b[1][1];
  	F= (a[1][0] - a[0][0]) * (b[0][0]+b[0][1]);
  	G= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
  	
  	
	c[0][0]=A+D-E+G;
	c[0][1]=C+E;
	c[1][0]=B+D;
	c[1][1]=A+C-B+F;

	
	printf("\n After multiplication \n");
	for(i=0;i<2;i++)
	{
		printf("\n");
		for(j=0;j<2;j++)
		{
			printf("%d, ",c[i][j]);
		}
	}
	printf("\n");
	return 0;
}
