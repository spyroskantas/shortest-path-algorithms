#include<stdio.h>
#include<stdlib.h>
#ifdef PATH
	int	DPATH=1;
#else
	int	DPATH=0;
#endif
#define INF 9999

void solve(int n, int **graph){
	int k,i,j,dist[n][n],**path;
	
	//if DEFINED PATH: first edge
	if(DPATH==1){
		//allocating space for path
		if ((path=malloc(n*sizeof(int*)))==NULL) return;
		for(i=0;i<n;i++)
			if ((path[i]=malloc(n*sizeof(int)))==NULL) return;	
			
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) 
				path[i][j]=i;
	}
			
 	for(i=1;i<n;i++)
		
		for(j=0;j<n;j++)
		
			if(graph[i][j]==-1)
				dist[i][j]=INF;
			else
				dist[i][j]=graph[i][j];
	
	for(k=1;k<n;k++)
	
		for(i=1;i<n;i++)
		
			for(j=0;j<n;j++)

				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					//if DEFINED PATH: middle edges
					if(DPATH==1)			
						path[i][j] = path[i][j]*10 + k;
				}
				
	//if DEFINED PATH: last edge
	if(DPATH==1){			
		for(i=0;i<n;i++)		
			for(j=0;j<n;j++) 
				path[i][j] = path[i][j]*10 + j; 
	}
		
	for(i=1;i<n;i++){
		
		for(j=0;j<i;j++){
				
			printf("from node %d to node %d: lenght of shortest path is %d\n",i,j,dist[i][j]);
			
			//if DEFINED PATH: print path
			if(DPATH==1){
				printf("shortest path is: %d",path[i][j]%10);
				path[i][j] = path[i][j]/10;
				while(path[i][j]%10){
					printf(" <- %d",path[i][j]%10);
					path[i][j] = path[i][j]/10;
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	
	//if DEFINED PATH: free path
	if(DPATH==1){
		for(i=0;i<n;i++)
			free(path[i]);
		free(path);
	}

	//free graph	
	for(i=0;i<n;i++)
		free(graph[i]);
	free(graph);
}
