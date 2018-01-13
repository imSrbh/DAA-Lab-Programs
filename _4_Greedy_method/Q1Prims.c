#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("Enter the number of Vertices in the graph : ");
	int n;
	scanf("%d",&n);
	printf("Enter the graph :\n");
	int G[n][n];
	int ST[n][n];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&G[i][j]);
			if(i!=j)
				ST[i][j]=-1;
			else
				ST[i][j]=0;
		}
	}

	// From here we Start the coding for Prim's Algorithm	
	int min;
	min=999999;
	int from;
	int to;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]>0 && min>G[i][j] )
			{
				min = G[i][j];
				from = i;
				to = j;
			}
		}
	}
	//printf("From : %d,to : %d\n",from,to);
	if(G[from][to]==G[to][from])
	{
		ST[from][to]=min;
		ST[to][from]=min;
		G[from][to]=-10;
		G[to][from]=-10;
	}	
	int visited[n];
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	visited[from]=1;
	visited[to]=1;
	int nvi = 2;
	while(nvi<n)
	{
		//printf("Enter the While loop\n");
		nvi++;
		min=999999;

		//printf("Selected min tmp cmp = %d\n",min);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(min>G[i][j]&& (visited[i]==1) && (visited[j]==0) && G[i][j]>0)
				{
					min = G[i][j];	
					from = i;
					to = j;
				}
			}
		}
		//printf("Selected Min = %d\n",min);
		//printf("From :%d , to : %d\n",from,to);
		visited[from]=1;
		visited[to]=1;
		if(G[from][to]==G[to][from])
		{
			ST[from][to]=G[from][to];
			ST[to][from]=G[from][to];		
			G[from][to]=-10;
			G[to][from]=-10;
		}
		else
		{
			ST[from][to]=G[from][to];
			G[from][to]=-10;
		}
	}
	//printf("And Finally");
	printf("The Spanning Tree is  :\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",ST[i][j]);
		printf("\n");
	}
}

	
