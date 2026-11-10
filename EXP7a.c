/* Implement kruskal's algorithm to find the Minimum Spanning Tree(MST) of a weighted connected graph */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10
struct Edge{
    int u,v,w;
};
struct Edge edge[MAX], temp;
int parent[MAX];
int find(int i){
    while(parent[i] != i) i = parent[i];
    return i;
}
void unionSet(int a,int b){
    parent[a] = b;
}

int main(){
    int V,E,cost = 0;
    printf("Enter the number of Vertices: ");
    scanf("%d",&V);
    printf("Enter the number of Edges: ");
    scanf("%d",&E);
    printf("Enter the source, destinationa and weight for each edge:\n");
    for(int i=0;i<E;i++) scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
    for(int i=0;i<V;i++) parent[i] = i;
    //bubble sort

    for(int i=0;i<E-1;i++){
        for(int j=0;j<E-i-1;j++){
            if(edge[j].w > edge[j+1].w){
                temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
            }
        }
    }
    printf("Minimum Spanning tree\n");
    for(int i=0;i<E;i++){
        int a = find(edge[i].u);
        int b = find(edge[i].v);
        if(a != b){
            printf("%d -- %d = %d\n",edge[i].u,edge[i].v,edge[i].w);
            cost += edge[i].w;
            unionSet(a,b);
        }
    }
    printf("The minimum cost is: %d",cost);
}