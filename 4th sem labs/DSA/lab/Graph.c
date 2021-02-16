#include<stdio.h>
#include<stdlib.h>

struct Graph{
	int V;
	int E;
	int Adj[10][10];
};
struct Graph *graphMatrix(){
	int i,j,k;
	struct Graph *G=(struct Graph *)malloc(sizeof(struct Graph));
	if(!G){
		printf("Memory Error");
		return;
	}
	printf("No. of Vertices and No of Edges: ");
	scanf("%d%d",&G->V,&G->E);
//	G->Adj=malloc(sizeof(G->V*G->V));
	for(i=0;i<G->V;i++){
		for(j=0;j<G->V;j++){
			G->Adj[i][j]=0;
		}
	}
	printf("\nGive Edge Pairs: (eg.: 1 3)\n");
	for(k=0;k<G->E;k++){
		scanf("%d%d",&i,&j);
		G->Adj[i-1][j-1]=1;
		G->Adj[j-1][i-1]=1;
	}
	printf("Check point 5"); 
	return G;
}
void printAdj(struct Graph *G){
	int i,j;
	printf("\nMatrix representation of graph is:\n");
	for(i=0;i<G->V;i++){
		for(j=0;j<G->V;j++){
			printf("%d ",G->Adj[i][j]);
		}
		printf("\n");
	}
}
int main(){
	struct Graph *G=NULL;
	G = graphMatrix();
	printAdj(G);
	printf("Check point 6");
	return 0;
}
