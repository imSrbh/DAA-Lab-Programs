#include<stdio.h>

#define stack 15
#define n 5
// Utitlity Codes
void printArray(int * arr,int len)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d, ",arr[i]);
	}
	printf("\n");
}

void printNicely(int *arr,int len,int src)
{
	int i=0;
		printf("\t,,,,,,,,,,,,,,,,,,,,\n");
	for(i=0;i<len;i++)
	{
		printf("\t|  %d to %d  |   %d   |\n",src,i,arr[i]);
	}
	printf("\t````````````````````\n");
}

// Codes for sample values 
void def_G(int G[n][n])
{
	G[0][0] = 0;
	G[0][1] = 2;
	G[0][2] = 500;
	G[0][3] = 500;
	G[0][4] = 3;

	G[1][0] = 5;
	G[1][1] = 0;
	G[1][2] = 4;
	G[1][3] = 7;
	G[1][4] = 500;

	G[2][0] = 500;
	G[2][1] = 500;
	G[2][2] = 0;
	G[2][3] = 3;
	G[2][4] = 500;

	G[3][0] = 500;
	G[3][1] = 500;
	G[3][2] = 5;
	G[3][3] = 0;
	G[3][4] = 1;

	G[4][0] = 7;
	G[4][1] = 1;
	G[4][2] = 500;
	G[4][3] = 6;
	G[4][4] = 0;
}



// Codes for stack

int stackArr[stack];
int top = 0;
int stack_push(int push)
{
	if(top==stack-1)
		return -1;
	else
	{
		stackArr[top]=push;
		top++;
		return 1;
	}
}

int stack_pop()
{
	if(top==0)
		return -1;
	else
	{
		top--;
		return stackArr[top];
	}
}

int stack_show()
{
	if(top==0)
		return -1;
	else
		return stackArr[top-1];
}

// codes for Dijkstra's Algo
int minimum(int a,int b)
{
	if(a<b)
		return a;
		
	else if(a>=b)
		return b;
}
		
	

void Dijkstra(int G[n][n],int src)
{
	int i,j,min,rv;
	int dist[n];
	int visit[n];
	int path[n];
	int len[n];
	for(j=0;j<n;j++)
	{
		visit[j]=0;
		dist[j]=-500;
		path[j]=1;
		len[j]=0;
	}
	visit[src]=1;
	dist[src]=0;
	int count=1;
	rv=src;
	while(count<n)
	{
		visit[rv]=1;
		for(j=0;j<n;j++)
		{
			if(dist[j]==-500)
			{
				dist[j]=G[src][j];
			}
			else if(visit[j]==0 && G[rv][j]!=500 &&G[rv][j]!=0 && G[rv][j]!=-1)
			{
				dist[j]=minimum(dist[j],dist[rv]+G[rv][j]);
			}
		}
		count++;
		for(i=0;i<n;i++)
		{
			if(visit[i]==0)
			{
				min = dist[i];
				rv=i;
				break;
			}
		}
		for(;i<n;i++)
		{
			if(min>dist[i] && dist[i]>0 && visit[i]==0)
			{
				min = dist[i];
				rv = i;
			}
		}
		//printf("Selected Min : %d, at %d\n",min,rv);
		//printArray(dist,n);
	}
	//printArray(dist,n);
	printNicely(dist,n,src);
}
			

int main()
{
	int i,j;
	int G[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			//scanf("%d",G[i][j]);
		}
	}
	def_G(G);
	int src;
	printf("Enter the source vertex : ");
	scanf("%d",&src);
	Dijkstra(G,src);
}


