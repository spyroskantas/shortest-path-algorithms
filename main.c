#include<stdio.h>
#include<stdlib.h>
#include"fheader.h"

int main(void){
	int a,i,j,n,**graph;   
         	
	scanf("%d",&n);
	
//allocating space
	if ((graph=malloc(n*sizeof(int*)))==NULL) return 1;
	for(i=0;i<n;i++)
		if (((graph[i])=malloc(n*sizeof(int)))==NULL) return 1;
		
//initializing graph
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			graph[i][j]=-1;
	for(i=0;i<n;i++) graph[i][i]=0;
		
//reading input
	for(i=1;i<n;i++)
		for(j=0;j<i;j++){
			scanf("%d",&a);
			graph[i][j]=a;
			graph[j][i]=a;
		}
	solve(n,graph);
	return 0;
}
