//To implement the list ADT using an array to perform insetion, deletion, searching and display elements

#include<stdio.h>
#define MAX 10

int arr[MAX];
int n = 0;

// Insert function

/*
pos = 2
ele = 6

0 1 2 3 4
2 3 4 5 6

0 1 2 3 4 5 
2 3 e 4 5 6
*/
void insert(int pos, int ele){
    if(n == MAX){
        printf("List overflow");
        return;
    }

    if(pos < 1 || pos > n+1){
        printf("Invalid position");
        return;
    }

    for(int i=n; i>=pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos-1] = ele;
    n++;

    printf("Element is inserted\n");
}

// Delete function
/*
pos = 2
0 1 2 3 4
2 3 4 5 6
*/
void delete(int pos){
    if(n == 0){
        printf("List Underflow");
        return;
    }

    if(pos < 1 || pos > n){
        printf("Invalid position");
        return;
    }

    int val = arr[pos-1];

    for(int i=pos-1; i<n-1; i++){
        arr[i] = arr[i+1];
    }

    n--;

    printf("Element %d is deleted\n",val);
}

// Search function
void search(int val){
    for(int i=0; i<n; i++){
        if(arr[i] == val){
            printf("Element found at position %d\n",i+1);
            return;
        }
    }

    printf("Element not found\n");
}

// Display function
void display(){
    if(n == 0){
        printf("List is empty\n");
        return;
    }

    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    printf("\n");
}

int main(){
    int ch,pos,ele;

    printf("1.Insert\n2.Delete\n3.Search\n4.Display\n");
    printf("Enter choice: ");
    scanf("%d",&ch);

    switch(ch){
        case 1:
            printf("Enter position and element: ");
            scanf("%d %d",&pos,&ele);
            insert(pos,ele);
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d",&pos);
            delete(pos);
            break;

        case 3:
            printf("Enter element to search: ");
            scanf("%d",&ele);
            search(ele);
            break;

        case 4:
            display();
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
