//To design and implement insertion,deletio and searching in a singly linked list

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insertBeg(int val){
    if(head == NULL){
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = NULL;
        head = temp;
        return;
    }
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    head = temp;
}
void insertEnd(int val){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
void insertPos(int pos,int val){
    if(pos == 1){
        insertBeg(val);
        return;
    }
    int count = 1;
    struct Node *temp = head;       
    while(temp != NULL && count < pos-1){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        printf("Position out of range!\n");
        return;
    }
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteBeg(){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return;
}
void deleteEnd(){
    struct Node *temp = head;
    if(head == NULL){
        printf("List is empty");
        return;
    }
    while(temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return;
}
void deletePos(int pos){
    struct Node *temp = head;
    if(head == NULL){
        printf("List is empty");
        return;
    }
    if(pos == 1){
        deleteBeg();
        return;
    }
    int count = 1;
    //struct Node *temp = head;
    while(temp->next != NULL && count < pos-1){
        temp = temp->next;
        count++;
    }
    struct Node *del = temp->next;
    temp->next = temp->next->next;
    free(del);
}
void search(int val){
    struct Node *temp = head;
    int posi = 1;
    while(temp != NULL){
        if(temp->data == val){
            printf("Found at %d",posi);
            return;
        }
        temp = temp->next;
        posi++;
    }
    printf("Element not found!");
}
void display(){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data); 
        temp = temp->next;
    }
    return;
}
int main(){
    int ch,val,pos; 
    while(1){
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter a value: ");
            scanf("%d",&val);
            insertBeg(val);
            break;
    
            case 2:
            printf("Enter a value: ");
            scanf("%d",&val);
            insertEnd(val);
            break;
    
            case 3:
            printf("Enter a value and position");
            scanf("%d %d",&pos,&val);
            insertPos(pos,val);
            break;
    
            case 4:
            deleteBeg();
            break;
    
            case 5:
            deleteEnd();
            break;
    
            case 6:
            printf("Enter a positon: ");
            scanf("%d",&pos);
            deletePos(pos);
            break;
    
            case 7:
            printf("Enter a value: ");
            scanf("%d",&val);
            search(val);
            break;
    
            case 8:
            display();
            break;

            case 9:
            return 0;

            default:
            printf("Invalid choice");
            break;
        }
    }
    
    return 0;
}