//To implement binary search tree -> insetion, searching, inorder,preorder and postorder

#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* creatNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int val){
    if(root == NULL) return creatNode(val);
    if(val < root->data) root->left = insert(root->left, val);
    else if(val > root->data) root->right = insert(root->right,val);
    else printf("Invalid value");
    return root;
}

void preorder(struct Node *root){
    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct Node *root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

struct Node* search(struct Node *root, int val){
    if(root == NULL || root->data == val) return root;
    if(val < root->data) return search(root->left, val);
    else if(val > root->data) return search(root->right,val);
    return NULL;
}
int main(){
    struct Node *root = NULL;
    root = insert(root,50);
    root = insert(root,30);
    root = insert(root,70);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,60);
    root = insert(root,80);

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    int val = 40;
    struct Node *temp = search(root,val);
    if(temp != NULL) printf("Found\n");
    else printf("Not found\n");

    val = 100;
    temp = search(root,val);
    if(temp != NULL) printf("Found");
    else printf("Not found");
    return 0;
}