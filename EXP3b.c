/*To convert an infix expression to postfix */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100
char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;
void push(char ch){
    if(top == MAX-1) return;
    stack[++top] = ch;
}
char pop(){
    if(top == -1) return -1;
    return stack[top--];
}
char peek(){
    if(top == -1) return -1;
    return stack[top];
}
int isEmpty(){
   return top == -1; 
}
int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int precedence(char ch){
    if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    return 0;
}
void infixToPostfix(char *infix, char *postfix){
    int i = 0,j = 0;
    char ch;
    while((ch = infix[i++]) != '\0'){
        if(isalnum(ch)) postfix[j++] = ch;
        else if(ch == '(') push(ch);
        else if(ch == ')'){
            while(!isEmpty() && peek() != '(') postfix[j++] = pop();
            pop();
        }else if(isOperator(ch)){
            while(!isEmpty() && precedence(peek()) >= precedence(ch)) postfix[j++] = pop();
            push(ch);
        }
    }
    while(!isEmpty()) postfix[j++] = pop();
    postfix[j] = '\0';
}
int main(){
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    infixToPostfix(infix,postfix);
    printf("Infix expression: %s\n",infix);
    printf("Postfix expression: %s",postfix);
    return 0;
}