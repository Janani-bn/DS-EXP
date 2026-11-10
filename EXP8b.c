/* Implement BFS */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
int g[MAX][MAX];
int vis[MAX];
int queue[MAX];
int V,front = -1,rear = -1;
void enqueue(int val){
    if(rear == MAX-1) return;
    if(front == -1) front = 0;
    queue[++rear] = val;
}
int dequeue(){
    return queue[front++];
}
int isEmpty(){
    return front > rear;
}
void bfs(int v){
    vis[v] = 1;
    enqueue(v);
    while(!isEmpty()){
        int vertex = dequeue();
        printf("%d ",vertex);
        for(int i=0;i<V;i++){
            if(g[vertex][i] == 1 && !vis[i]){
                vis[i] = 1;
                enqueue(i);
            }
        }
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
    printf("BFS Traversal:\n");
    bfs(src);
    return 0;
}
