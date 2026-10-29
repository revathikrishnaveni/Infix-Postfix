#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define MAX 100
extern char stack[MAX];
extern int top;

int isOperand(char ch);
void push(char data);
char pop();
int priority(char ch);
int infixtopostfix(char *infix,char *postfix);



