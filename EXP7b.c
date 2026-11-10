/* Implement kruskal's algorithm to find the Minimum Spanning Tree(MST) of a weighted connected graph */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10
#define INF 99999
int g[MAX][MAX];
int vis[MAX];
int main(){
    int V,min,x,y,cost = 0;
    printf("Enter the numebrof vertices: ");
    scanf("%d",&V);
    printf("Enter the adjacency matrix: ");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&g[i][j]);
            if(g[i][j] == 0) g[i][j] = INF;
        }
    }
    for(int i=0;i<V;i++) vis[i] = 0;
    vis[0] = 1;
    int count = 0;
    printf("The minimum spanning tree\n");
    while(count < V-1){
        min = INF;
        x=0,y=0;
        for(int i=0;i<V;i++){
            if(vis[i]){
                for(int j=0;j<V;j++){
                    if(!vis[j] && g[i][j]){
                        if(min > g[i][j]){
                            min = g[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d -- %d = %d\n",x,y,g[x][y]);
        cost += g[x][y];
        vis[y] = 1;
        count++;
    }
    printf("The minimum cost is: %d",cost);
}