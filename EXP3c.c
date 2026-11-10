/* Evaluation of a postfix expression */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(int val){
    if(top == MAX-1) return;
    stack[++top] = val;
}
int pop(){
    if(top == -1) return -1;
    return stack[top--];
}
int peek(){
    if(top == -1) return -1;
    return stack[top];
}
int isEmpty(){
    return top == -1; 
}
int evaluatePostfix(char *expr){
    for(int i=0;expr[i] != '\0';i++){
        char ch = expr[i];
        if(isdigit(ch)){
            push(ch - '0');
        }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int b = pop();
            int a = pop();
            switch(ch){
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/':
                    if(b == 0){
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(a / b);
                    break;
            }
        }
    }
    return pop();
}
int main(){
    char expr[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s",expr);
    printf("Result: %d\n",evaluatePostfix(expr));
    return 0;
}