#include "header.h"
int infixtopostfix(char *infix,char *postfix)
{
	int i,j=0;
	char ch;
	top=-1;
	for(i=0;infix[i]!= '\0';i++)
	{
		ch=infix[i];
		if(isOperand(ch))
		{
			if(i>0 && isOperand(infix[i-1]))
			{
				return 0;
			}
			postfix[j++]=ch;
		}
		else if(ch == '(' || ch == '{' || ch == '[')
		{
			if(i>0 && (isOperand(infix[i-1])||infix[i-1]==')'||infix[i-1]=='}'||infix[i-1]==']'))
			{
				return 0;
			}
			push(ch);
		}
		else if(ch == ')' || ch == '}' || ch == ']')
		{
			if(top==-1)
			{
				return 0;
			}
			if(i==0||(!isOperand(infix[i-1]) && infix[i-1]==')' && infix[i-1]=='}' && infix[i-1]==']'))
			{
				return 0;
			}
			while(top!= -1 && stack[top]!='(' && stack[top]!='{' && stack[top]!='[')
			{
				postfix[j++] = pop();
			}
			if(top==-1)
			{
				return 0;
			}
			if((ch == ')'&& stack[top] != '(')||(ch == '}' && stack[top] != '{') || (ch == ']' && stack[top] != '['))
			{
				return 0;
			}
			pop();
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^')
		{
			if(i==0 ||(!isOperand(infix[i-1]) && infix[i-1]==')' && infix[i-1]=='}' && infix[i-1]==']'))
			{
				return 0;
			}
			if(infix[i+1]=='\0'||infix[i+1]=='+'||infix[i+1]=='*'||infix[i+1]=='-'||infix[i+1]=='/'||infix[i+1]=='^'||infix[i+1]=='%'||infix[i+1]==')'||infix[i+1]=='}'||infix[i+1]==']')
			{
				return 0;
		        }
			while(top!=-1 && stack[top]!='(' && stack[top]!='{' && stack[top]!='[' && (priority(stack[top])>priority(ch)||(priority(stack[top])==priority(ch) && ch != '^')))
			{
				postfix[j++]=pop();
			}
			push(ch);
		}
		else
		{
			return 0;
		}
	}
	while(top!=-1)
	{
		if(stack[top]=='('||stack[top]=='{'||stack[top]=='[')
		{
			return 0;
		}
		postfix[j++] = pop();
	}
	postfix[j] = '\0';
	return 1;
}


