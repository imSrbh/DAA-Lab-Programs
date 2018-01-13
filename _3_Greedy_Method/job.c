#include<stdio.h>
#include<stdlib.h>

int largest(int p[],int arr[],int n,int *d){
	int i,j,max,k=0;
	
	max=p[k];
	for(i=0;i<n;i++){
		if(max<p[i]){
			max=p[i];
			k=i;
		}}
	
	if(arr[d[k]]==-1 && k>=0){
		arr[d[k]]=p[k];
		p[k]=0;
	    }
	    else if(arr[d[k]]!=-1 && k>=0){
	    	arr[d[k]-1]=p[k];
	    	p[k]=0;
	    	}
	    	
	  return 0;
	  } 
	
			
		
int main(){
	int i,j,n,max,k,temp;
	printf("Enter the number of jobs :");
	scanf("%d",&n);
	int p[n],d[n];
	printf("ENter the profits : ");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
		}
	printf("Enter the deadlines : ");
	for(i=0;i<n;i++){
		scanf("%d",&d[i]);
		}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(p[i]<p[j]){
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	} 
	max=d[0];
	for(i=0;i<n;i++){
		if(max<d[i]){
			max=d[i];
			k=i;
		}
	}
	int arr[max+1];
	for(i=0;i<max;i++)
		arr[i]=-1;
	arr[max]=p[k];
	p[k]=0;
	k=0;
	for(i=1;i<max;i++){
		largest(p,arr,n,d);	
		}
	
	for(i=1;i<max+1;i++){
		printf("-> %d",arr[i]);
		}
	//printf(".\n");
	return 0;
	}
		
				
