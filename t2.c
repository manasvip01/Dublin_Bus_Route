#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"t2.h"
#define SIZE 100 
int num_edges=0;
int GRAPH[MAX][MAX];
// int minv1=INT_MAX;
// int minv2=INT_MAX;
struct edges 
{
    int vertex1;
    int vertex2;
    int weight;
};
struct vertices 
{
    int vertex;
    char name[100];
    float latitude;
    float longitude;
};

// int min(int a,int b){
//     return(a>b) ? b: a;
// }
int next_field( FILE *f, char *buf, int max ) //Referred from solutions of Assignment 0
{
    int i=0, end=0, quoted=0;
    for(;;) {
        buf[i] = fgetc(f);
        if(buf[i]=='"') { quoted=!quoted; buf[i] = fgetc(f); }
        if(buf[i]==',' &&  !quoted) { break; }
        if(feof(f) || buf[i]=='\n') { end=1; break; } 
        if( i<max-1 ) { ++i; } 
    }
    buf[i] = 0; 
    return end;
}
void fetch_title (FILE *csv, struct edges *p )//Referred from solutions of Assignment 0
{
    char buf[SIZE];
    next_field( csv, buf, SIZE );
    p->vertex1=atoi(buf);
    next_field( csv, buf, SIZE );
    p->vertex2=atoi(buf);
    next_field( csv, buf, SIZE );
    p->weight=atoi(buf);
    GRAPH[p->vertex1][p->vertex2]=p->weight;
 }
 void fetch_title1 (FILE *csv, struct vertices *p )//Referred from solutions of Assignment 0
{
    char buf[SIZE];
    next_field( csv, buf, SIZE );
	p->vertex=atoi(buf);
    next_field( csv, p->name, SIZE );
    next_field( csv, buf, SIZE );
	p->latitude=atoi(buf);
    next_field( csv, buf, SIZE );
	p->longitude=atoi(buf);
 }

 int load_edges(char *fname){
    // FILE *fname=&f;
    FILE *f = fopen(fname, "r");
    struct edges *value;
    int count=0;
    value=(struct edges *)malloc(sizeof(struct edges));
    fetch_title(f,value);
    while(!feof(f))
    {
        fetch_title(f,value);
        count++;
    }
    return printf("Loaded %d edges\n",count);
}

int load_vertices(char *fname){
    // FILE *fname=&f;
    FILE *f = fopen(fname, "r");
    struct vertices *value;
    int count=0;
    value=(struct vertices *)malloc(sizeof(struct vertices));
    fetch_title1(f,value);
    while(!feof(f))
    {
        fetch_title1(f,value);
        count++;
    }
    return printf("Loaded %d vertices\n",count);
}
void Dijkstra(int Graph[MAX][MAX], int n, int start,int end) {
    printf("HII");
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, minDistance, nextNode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      if (Graph[i][j] == 0)
        cost[i][j] = 20000;
      else
        cost[i][j] = Graph[i][j];
    }
  }
    // for(int i=minv1;i<n;i++){
    //     for(int j=minv2;j<n;j++){
    //         printf("%d\t",i);
    //         printf("%d\t",j);
    //         printf("%d\t",Graph[i][j]);
    //         printf("\n");
    //     }
    // }
  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    minDistance = 20000;

    for (i = 0; i < n; i++)
      if (distance[i] < minDistance && !visited[i]) {
        minDistance = distance[i];
        nextNode = i;
      }

    visited[nextNode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (minDistance + cost[nextNode][i] < distance[i]) {
          distance[i] = minDistance + cost[nextNode][i];
          pred[i] = nextNode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++){
  int j;
    if (i !=start) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
      printf("\nPath=%d",i);
      j=i;
      do{
        j=pred[j];
        printf("<-%d",j);
      } while(j!=start);
    }
}
}
void shortest_path(int startNode, int endNode){
	Dijkstra(GRAPH,num_edges,startNode,endNode);
} // prints the shortest path between startNode and endNode, if there is any
void free_memory ( void ){

} // frees any memory that was used

int main (int argc, char *argv[] ) {
    if ( argc < 3 ) {
		printf("usage: ./bus VERTICES EDGES\n");
		return EXIT_FAILURE;
	}
    // FILE *f = fopen(argv[1], "r");
	if ( !load_vertices( argv[1] ) ) {
		printf("Failed to load vertices\n");
		return EXIT_FAILURE;
	}

	if ( !load_edges( argv[2] ) ) {
		printf("Failed to load edges\n");		
		return EXIT_FAILURE;
	}
 printf("Please enter stating bus stop >\t\t");
    int startingNode;
    scanf("%d", &startingNode);
    printf("Please enter destination bus stop >\t");
    int endingNode;
    scanf("%d", &endingNode);

	shortest_path(startingNode, endingNode);
    

	free_memory();

	return EXIT_FAILURE;
}
