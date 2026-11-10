/* Implement Dijkstra's algorithm and find the shortest path from a source vertex to all other
vertices in a weighted directed graph */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define V 5
#define MAX 10
//int graph[MAX][MAX];
int dist[MAX];
int vis[MAX];
int graph[5][5] = {
    {0,10,0,0,5},
    {10,0,1,0,2},
    {0,1,0,4,0},
    {0,0,4,0,0},
    {5,2,0,0,0}
};
int minDist(){
    int minVal = INT_MAX, minInd = 0;
    for(int i=0;i<V;i++){
        if(!vis[i] && dist[i] <= minVal){
            minVal = dist[i];
            minInd = i;
        }
    }
    return minInd;
}
void dijkstra(int src){
    for(int i=0;i<V;i++){
        vis[i] = 0;
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for(int cnt = 0;cnt < V;cnt++){
        int u = minDist();
        if(u == -1) break;
        vis[u] = 1;
        for(int v=0;v<V;v++){
            if(!vis[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];
        }
    }
}
void display(int src){
    printf("\nShortest path from source %d\n",src);
    printf("------------------------------\n");
    printf("Vertex\t\tDistance\n");
    printf("------------------------------\n");
    for(int i=0;i<V;i++){
        printf(" %d\t\t",i);
        if(dist[i] == INT_MAX) printf("Unreachable\n");
        else printf("%d\n",dist[i]);
    }
    printf("------------------------------\n");
}
int main(){
    printf("Adjacency Matrix\n\n");
    for(int i=0;i<V;i++){
        for(int ind=0;ind<V;ind++){
            printf("%d ",graph[i][ind]);
        }
        printf("\n");
    }
    int src = 0;
    dijkstra(src);
    display(src);
    return 0;
}