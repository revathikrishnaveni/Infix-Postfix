#include "header.h"
char stack[MAX];
int top = -1;
void push(char data)
{
	stack[++top] = data;	
}
char pop()
{
	return stack[top--];
}
int priority(char ch)
{
	if(ch == '^')
		return 3;
	if(ch == '*' || ch == '/' || ch == '%')
		return 2;
	if(ch == '+' || ch == '-')
		return 1;
	return 0;
}

