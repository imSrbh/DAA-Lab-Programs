#include<stdio.h>
 int l=0;
 int min(int i,int j,int c[100][100])
 {
    int k,a[k],min=9999999;
    for(k=i+1;k<=j;k++)
    {
        a[k]=c[i][k-1]+c[k][j];
        if(a[k]<min)
            {
                min=a[k];
                l=k;
            }
    }
    return min;
 }
int main()
{
    int c[100][100],r[100][100],w[100][100],p[100],q[100],n,i,j,k;
    printf("Enter the total number vertex in bst\n");
    scanf("%d",&n);
    printf("Enter the p value\n");
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("Enter the corresponding q value\n");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&q[i]);
    
    }
   /* for(i=0;i<a;i++)
        for(j=0;j<a;j++)
        {
            c[i][j]=0;
            r[i][j]=0;
        }*/
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            {
                if(i==j)
                {
                    w[i][j]=q[i];
                }
                else
                {
                    w[i][j]=p[j-1]+q[j]+w[i][j-1];
                }
            }
    for(k=0;k<=n;k++)
    {
        for(i=0,j=k;i<=n;i++,j++)
        {
             if(i==j)
            {
                c[i][j]=0;
                r[i][j]=0;
            }
            else
            {
                c[i][j]=min(i,j,c)+w[i][j];
                r[i][j]=l;
            }

        }
    }
  for(k=0;k<=n;k++)
    {
        for(i=0,j=k;i<=n;i++,j++)
        {
            printf("c[%d][%d]=%d and r[%d][%d]=%d and w[%d][%d]=%d\n",i,j,c[i][j],i,j,r[i][j],i,j,w[i][j]);
        }
        printf("\n");
    }
    printf("optimal cost is  %d and k is %d\n",c[0][n],r[0][n]);
    return 0;
}
