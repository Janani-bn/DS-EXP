/* Implement Topological Sorting */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
int g[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1,V;
int main(){
    int src;
    printf("Enter the number of vertices: ");
    scanf("%d",&V);
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<V;i++){
        for(int ind=0;ind<V;ind++){
            scanf("%d",&g[i][ind]);
            if(g[i][ind] == 1) indegree[ind]++;
        }
    }
    for(int i=0;i<V;i++){
        if(indegree[i] == 0) queue[++rear] = i;
    }
    printf("Topological Ordering: ");
    int count = 0;
    while(front <= rear){
        int vertex = queue[front++];
        printf("%d ",vertex);
        count++;
        for(int i=0;i<V;i++){
            if(g[vertex][i] == 1){
                indegree[i]--;
                if(indegree[i] == 0) queue[++rear] = i;
            }
        }
    }
    if(count != V) printf("Graph contains a cycle");
    return 0;
}