#include "header.h"
int isOperand(char ch)
{
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
	{
		return 1;
	}
	return 0;
}

