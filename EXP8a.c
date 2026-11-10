/* Implement DFS */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
int g[MAX][MAX];
int vis[MAX];
int V;
void dfs(int v){
    vis[v] = 1;
    printf("%d ",v);
    for(int i=0;i<V;i++){
        if(g[v][i] == 1 && !vis[i]) dfs(i);
    }
}
int main(){
    int src;
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<V;i++){
        for(int ind=0;ind<V;ind++) scanf("%d",&g[i][ind]);
    }
    printf("Enter the starting vertex: ");
    scanf("%d",&src);
    for(int i=0;i<V;i++) vis[i] = 0;
    printf("DFS Traversal:\n");
    dfs(src);
    return 0;
}