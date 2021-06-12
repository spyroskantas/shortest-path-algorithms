#include<stdio.h>
#include<stdlib.h>


//shortest path function
int srtpath(int i, int j, int k, int **graph, int ***P){
	
	int d1,d2,d3;
	
	if (k<0) return graph[i][j];
	
	//memory
	if (P[i][j][k]==-2){
	
		d1=srtpath(i,j,k-1,graph,P);
		d2=srtpath(i,k,k-1,graph,P);
   	 	d3=srtpath(k,j,k-1,graph,P);
    
		if(d1<0 && d2<0 && d3<0) P[i][j][k] = -1;
		else if (d1>0 && (d2<0 || d3<0)) P[i][j][k] = d1;
		else if(d1<0 && (d2>0 && d3>0)) P[i][j][k] = d2+d3;
		else if(d1<d2+d3)
			P[i][j][k] = d1;
		else 
			P[i][j][k] = d2+d3;
		
	}
	return P[i][j][k];
}

int k2; //for P initialization
	
//solve function				
void solve(int n, int **graph){
	int i,j,***P;
	
	//allocating space for P
	if ((P=malloc(n*sizeof(int**)))==NULL) return;
	for(i=0;i<n;i++)
		if (((P[i])=malloc(n*sizeof(int*)))==NULL) return;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if (((P[i][j])=malloc(n*sizeof(int)))==NULL) return;
				
	//initializing P
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k2=0;k2<n;k2++)
				P[i][j][k2]=-2;	
				
	//print results			
	for(i=1;i<n;i++){
	
		for(j=0;j<i;j++){
			
			graph[i][j] = srtpath(i,j,n-1,graph,P);
			if(graph[i][j] != -1) printf("From node %d to node %d: Length of shortest path is %d\n",i,j,graph[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			free(P[i][j]);
		free(P[i]);
	}
	free(P);
		
	for(i=0;i<n;i++) 
		free (graph[i]);
	free (graph);
}
