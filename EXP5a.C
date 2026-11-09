//Implementation of AVL tree using templates

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

int getMax(int a,int b){
    return a > b ? a : b;
}

int findHeight(struct Node *root){
    if(root == NULL) return 0;
    return root->height;
}

int getBalance(struct Node *root){
    if(root == NULL) return 0;
    return findHeight(root->left) - findHeight(root->right);
}

struct Node* createNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

struct Node* rightRotation(struct Node *y){
    struct Node *x = y->left;
    struct Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = getMax(findHeight(y->left),findHeight(y->right))+1;
    x->height = getMax(findHeight(x->left),findHeight(x->right))+1;

    printf("RR at %d\n",y->data);
    return x;
}

struct Node* leftRotation(struct Node *x){
    struct Node *y = x->right;
    struct Node *t1 = y->left;

    y->left = x;
    x->right = t1;

    y->height = getMax(findHeight(y->left),findHeight(y->right))+1;
    x->height = getMax(findHeight(x->left),findHeight(x->right))+1;

    printf("LR at %d\n",x->data);
    return y;
}

struct Node* insert(struct Node *node, int val){
    if(node == NULL) return createNode(val);
    else if(val < node->data) node->left = insert(node->left,val);
    else if(val > node->data) node->right = insert(node->right,val);
    else{
        printf("Invalid Value");
        return node;
    }
    

    node->height = getMax(findHeight(node->left),findHeight(node->right))+1;

    int bal = getBalance(node);

    if(bal > 1 && node->left != NULL && val < node->left->data) 
        return rightRotation(node);

    // Left Right (LR) Case: bal > 1 and inserted into left-right
    if(bal > 1 && node->left != NULL && val > node->left->data){
        node->left = leftRotation(node->left); 
        return rightRotation(node);
    }

    // Right Right (RR) Case: bal < -1 and inserted into right-right
    if(bal < -1 && node->right != NULL && val > node->right->data) 
        return leftRotation(node);

    // Right Left (RL) Case: bal < -1 and inserted into right-left
    if(bal < -1 && node->right != NULL && val < node->right->data){
        node->right = rightRotation(node->right); 
        return leftRotation(node);
    }
    return node;
}

void display(struct Node *root){
    if(root == NULL) return;
    display(root->left);
    printf("Node: %d | Height: %d | Balance Factor: %d\n",root->data,root->height,getBalance(root));
    display(root->right);
}
int main(){
    struct Node *root = NULL;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);
    printf("\n");
    display(root);
    return 0;
}