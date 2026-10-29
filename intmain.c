#include<stdio.h>
#include "header.h"
int main()
{
	char infix[MAX];
	char postfix[MAX];
	char choice;
	while(1)
	{
		printf("enter the choice:\n");
		printf("i:infix e:exit\n");
		__fpurge(stdin);
		scanf("%c",&choice);
		switch(choice)
		{
			case 'i':printf("enter the infix expression\n");
				 scanf("%s",infix);
				 if(infixtopostfix(infix,postfix))
				 {
					 printf("postfix expression:%s\n",postfix);
				 }
				 else
				 {
					 printf("invalid expression\n");
				 }
				 break;
			case 'e':exit(0);
		}
	}
	
}

