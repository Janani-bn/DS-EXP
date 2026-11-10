/* Implementation polynomial ADT using linked list */
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coeff;
    int expo;
    struct Node *next;
};
struct Node* creatNode(int coeff,int expo){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct Node **head, int coeff, int expo){
    struct Node *newNode = creatNode(coeff,expo);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
void display(struct Node *head){
    if(head == NULL){
        printf("0\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL){
        printf("%dx^%d", temp->coeff, temp->expo);
        if(temp->next != NULL) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
struct Node* addPoly(struct Node *p1, struct Node *p2){
    struct Node *res = NULL;
    while(p1 != NULL && p2 !=  NULL){
        if(p1->expo == p2->expo){
            insertTerm(&res, p1->coeff+p2->coeff,p1->expo);
            p1 = p1->next;
            p2 = p2->next;
        }else if(p1->expo > p2->expo){
            insertTerm(&res, p1->coeff,p1->expo);
            p1 = p1->next;
        }else if(p2->expo > p1->expo){
            insertTerm(&res, p2->coeff,p2->expo);
            p2 = p2->next;
        }
    }
    while(p1 != NULL){
        insertTerm(&res,p1->coeff,p1->expo);
        p1 = p1->next;
    }
    while(p2 != NULL){
        insertTerm(&res,p2->coeff,p2->expo);
        p2 = p2->next;
    }
    return res;
}
int main(){
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;
    insertTerm(&poly1,3,3);
    insertTerm(&poly1,5,2);
    insertTerm(&poly1,2,0);

    insertTerm(&poly2,4,3);
    insertTerm(&poly2,2,2);
    insertTerm(&poly2,1,0);

    printf("Polynomial1\n");
    display(poly1);
    printf("Polynomial2\n");
    display(poly2);
    sum = addPoly(poly1, poly2);
    printf("Sum polynomial2\n");
    display(sum);
}