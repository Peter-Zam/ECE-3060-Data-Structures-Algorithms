#include<stdio.h>
#define V 5
//init matrix to 0
void init(int arr[V][V])
{
    int i,j;
    for(i = 0; i < V; i++)
    	for(j = 0; j < V; j++)
			arr[i][j] = 0;
}
//Add edge. set arr[src][dest] = 1
void addEdge(int arr[V][V],int src, int dest)
{
     arr[src][dest] = 1;
}
//print the adjMatrix
void printAdjMatrix(int arr[V][V])
{
     int i, j;
     printf("Adjacency Matrix is \n\n");
     printf("    ");
     for(j=0; j<V; j++)
     {
     	printf("%d ", j+1);
     }
     printf("\n");
	 for(i = 0; i < V; i++)
     {
         printf("%d [ ", i+1);
		 for(j = 0; j < V; j++)
         {
             printf("%d ", arr[i][j]);
         }
         printf("]");
         printf("\n");       
     }
}
int main()
{
    int adjMatrix[V][V];
	init(adjMatrix);
    addEdge(adjMatrix,0,1);
    addEdge(adjMatrix,0,2);
    addEdge(adjMatrix,0,3);
    addEdge(adjMatrix,1,2);
    addEdge(adjMatrix,2,1);
    addEdge(adjMatrix,3,3);
    addEdge(adjMatrix,4,1);
    printAdjMatrix(adjMatrix);
    printf("\n");
    return 0;
}