#include<stdio.h>
#include<stdlib.h>

//shortest path function
int srtpath(int i, int j, int k, int **graph){
	
	int d1,d2,d3;
	if (k<0) return graph[i][j];
	d1=srtpath(i,j,k-1,graph);
	d2=srtpath(i,k,k-1,graph);
	d3=srtpath(k,j,k-1,graph);
	
	if(d1<0 && d2<0 && d3<0) return -1;
	else if (d1>0 && (d2<0 || d3<0)) return d1;
	else if(d1<0 && (d2>0 && d3>0)) return d2+d3;
	else return (d1<d2+d3)? d1:d2+d3;
}

//solve function
void solve(int n, int **graph){
	int i,j;
	
	for(i=1;i<n;i++){
	
		for(j=0;j<i;j++){
			
			graph[i][j]=srtpath(i,j,n-1,graph);
			if(graph[i][j]!=-1) printf("From node %d to node %d: Length of shortest path is %d\n",i,j,graph[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++) free (graph[i]);
	free (graph);
}
