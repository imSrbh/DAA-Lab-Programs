#include<stdio.h>

int retur[100];
int* set_priority(int* profit,int* weigth, int len)
{
	float pi[len];
	//int retur[len];
	for(int i=0;i<len;i++)
	{
		pi[i]=(float)(profit[i]/weigth[i]);
	}
	int k=0;
	for(int i=0;i<len;i++)
	{
		int max=pi[0],maxindex=0,j;
		for(j=0;j<len;j++)
		{
			if(max>pi[j])
			{
				max=pi[j];
				maxindex=j;
			}
		}
		pi[maxindex]=-1;
		retur[maxindex]=k;
		k++;
	}
	return retur;
}

void knapsack(int n, int *profit, int *weigth, int k)
{

	int* pi=set_priority(profit,weigth,n);
	int cap=k;
	int i=0;
	float seq[n];
	float total_profit=0;
	while(cap>0)
	{
		if(cap>=weigth[pi[i]])
		{
			seq[pi[i]]=1.0;
			cap-=weigth[pi[i]];
			total_profit+=profit[pi[i]];
		}
		else
		{
			seq[pi[i]]=(float)cap/(float)weigth[pi[i]];
			cap=0;
			total_profit+=profit[pi[i]]*seq[pi[i]];
		}
		i++;
	}
	for(;i<n;i++)
	{
		seq[pi[i]]=0.0;
	}
	printf("The Total Profit is : %f\n",total_profit);
	printf("\nThe sequence is : (");
	for(i=0;i<n;i++)
	{
		printf("%d, ",pi[i]);
	}
	printf(")");
}

int main()
{
	int n,k;
	printf("Enter the number of objects : ");
	scanf("%d",&n);
	printf("Enter the profit and weigth respectively :\n");
	int profit[n],weigth[n];
	printf("Profit : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&profit[i]);
	}
	printf("Weigth : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&weigth[i]);
	}
	printf("Enter the Knapsack capacity : ");
	scanf("%d",&k);
	knapsack(n,profit,weigth,k);
}
