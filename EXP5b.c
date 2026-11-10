//Implementaion of Heap tree (max heap, min heap) using templates

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// MAX HEAP IMPLEMENTATION

int maxHeap[MAX];
int maxSize = 0;
void swapMax(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUpMax(int ind){
    int parent = (ind-1)/2;
    while(ind > 0 && maxHeap[ind] > maxHeap[parent]){
        swapMax(&maxHeap[ind],&maxHeap[parent]);
        ind = parent;
        parent = (ind-1)/2;
    }
}
void heapifyDownMax(int index){
    int largest  = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left < maxSize && maxHeap[left] > maxHeap[largest]) largest = left;
    if(right < maxSize && maxHeap[right] > maxHeap[largest]) largest = right;
    if(largest != index){
        swapMax(&maxHeap[largest],&maxHeap[index]);
        heapifyDownMax(largest);
    }
}
void insertMax(int val){
    if(maxSize >= MAX){
        printf("Max heap is full\n");
        return;
    }
    maxHeap[maxSize] = val;
    maxSize++;
    heapifyUpMax(maxSize-1);
    printf("%d inserted in min heap\n",val);
}
void deleteMax(){
    if(maxSize == 0){
        printf("Max heap is empty");
        return;
    }
    maxHeap[0] = maxHeap[maxSize-1];
    maxSize--;
    printf("Element deleted in max heap\n");
    heapifyDownMax(0);
}
void displayMax(){
    if(maxSize == 0){
        printf("Max heap is empty\n");
        return;
    }
    printf("-----MAX HEAP-----\n");
    for(int i=0;i<maxSize;i++) printf("%d ",maxHeap[i]);
    printf("\n");
}

//MIN HEAP IMPLEMENTATION

int minHeap[MAX];
int minSize = 0;
void swapMin(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUpMin(int index){
    int parent = (index-1)/2;
    while(index > 0 && minHeap[index] < minHeap[parent]){
        swapMin(&minHeap[index],&minHeap[parent]);
        index = parent;
        parent = (index-1)/2;
    }
}
void heapifyDownMin(int ind){
    int smallest = ind;
    int left = 2*ind+1;
    int rigth = 2*ind+2;

    if(ind < minSize && minHeap[left] < minHeap[smallest]) smallest = left;
    if(ind < minSize && minHeap[rigth] < minHeap[smallest]) smallest = rigth;
    if(ind != smallest){
        swapMin(&minHeap[ind],&minHeap[smallest]);
        heapifyDownMin(smallest);
    }
}
void insertMin(int val){
    if(minSize >= MAX){
        printf("Min heap is full\n");
        return;
    }
    minHeap[minSize] = val;
    minSize++;
    heapifyUpMin(minSize-1);
    printf("%d inserted in min heap\n",val);
}
void delelteMin(){
    if(minSize == 0){
        printf("Min heap is empty");
        return;
    }
    minHeap[0] = minHeap[minSize-1];
    minSize--;
    heapifyDownMin(0);
    printf("Element is deleted in min heap\n");
}
void dispalyMin(){
    if(minSize == 0){
        printf("Min heap is empty");
        return;
    }
    printf("-----MIN HEAP-----\n");
    for(int i=0;i<minSize;i++) printf("%d ",minHeap[i]);
    printf("\n");
}
int main(){
    printf("=====MAX HEAP=====\n");
    insertMax(10);
    insertMax(20);
    insertMax(15);
    insertMax(40);
    insertMax(50);
    insertMax(25);
    displayMax();
    deleteMax();
    displayMax();
    printf("=====MIN HEAP=====\n");
    insertMin(10);
    insertMin(20);
    insertMin(15);
    insertMin(40);
    insertMin(50);
    insertMin(25);
    dispalyMin();
    delelteMin();
    dispalyMin();
}
