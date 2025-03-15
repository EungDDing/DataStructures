#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "ListStack.h"
using namespace std;

class Calculate
{
public:
	char* exp;
	ListStack<char> stack;
public:
	Calculate(char* arr)
	{
		exp = new char[strlen(arr) + 1];
		strcpy(exp, arr);
	}
	int GetOpPrec(char op)
	{
		switch (op)
		{
		case '*':
		case '/':
			return 5;
		case '+':
		case '-':
			return 3;
		case '(':
			return 1;
		}

		return -1;
	}
	int WhoPrecOp(char op1, char op2)
	{
		int op1Prec = GetOpPrec(op1);
		int op2Prec = GetOpPrec(op2);

		if (op1Prec > op2Prec)
			return 1;
		else if (op1Prec < op2Prec)
			return -1;
		else
			return 0;
	}

	void ConvToRPNExp()
	{
		char* convExp = new char[strlen(exp) + 1];

		int idx = 0;
		char tok, popOp;

		fill(convExp, convExp + strlen(exp) + 1, '\0');
		
		for (int i = 0; i < strlen(exp); i++)
		{
			tok = exp[i];
			if (isdigit(tok))
			{
				convExp[idx++] = tok;
			}
			else
			{
				switch (tok)
				{
				case '(':
					stack.SPush(tok);
					break;
				case ')':
					while (true)
					{
						popOp = stack.SPop();
						if (popOp == '(')
							break;
						convExp[idx++] = popOp;
					}
					break;
				case '*':
				case '/':
				case '+':
				case '-':
					while (!stack.SIsEmpty() && WhoPrecOp(stack.SPeek(), tok) >= 0)
						convExp[idx++] = stack.SPop();

					stack.SPush(tok);
					break;
				}
			}
		}
		while (!stack.SIsEmpty())
			convExp[idx++] = stack.SPop();

		strcpy(exp, convExp);
		delete[] convExp;
	}
	int EvalRPNExp()
	{
		int expLen = strlen(exp);
		int i;
		char tok, op1, op2;

		for (i = 0; i < expLen; i++)
		{
			tok = exp[i];

			if (isdigit(tok))
			{
				stack.SPush(tok - '0');
			}
			else
			{
				op2 = stack.SPop();
				op1 = stack.SPop();
				
				switch (tok)
				{
				case '+':
					stack.SPush(op1 + op2);
					break;
				case '-':
					stack.SPush(op1 - op2);
					break;
				case '*':
					stack.SPush(op1 * op2);
					break;
				case '/':
					stack.SPush(op1 / op2);
					break;
				}
			}
		}
		return stack.SPop();
	}
	int EvalInfixExp()
	{	
		int ret;
		ConvToRPNExp();
		ret = EvalRPNExp();

		return ret;
	}
};