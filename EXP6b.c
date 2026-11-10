/*
Implement Floyd Warshall Algorithm to find the shortest path between all pairs of vertices 
in a weighted directed graph
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10
#define INF 99999
int V;
//int dist[MAX][MAX];
int dist[4][4] = {
    {0,3,INF,7},
    {8,0,2,INF},
    {5,INF,0,1},
    {2,INF,INF,0}
};
void floydWarshall(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k]+dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}
int main(){
    V = 4;
    printf("Initial distance matrix\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j] == INF) printf("INF ");
            else printf(" %d ",dist[i][j]);
        }
        printf("\n");
    }
    floydWarshall();
    printf("\nDistance matrix after floyd warshall\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j] == INF) printf("INF ");
            else printf(" %d ",dist[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\nShortest path between all pairs\n");
    printf("-------------------------------\n");
    printf("Sourec \t Destination \t Shortest distance\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i != j){
                printf("%d\t\t%d\t",i,j);
                if(dist[i][j] == INF) printf("\tUnreachable\n");
                else printf("\t%d\n",dist[i][j]);
            }
        }
        //printf("\n");
    }
}