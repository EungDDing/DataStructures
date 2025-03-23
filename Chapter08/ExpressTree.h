#pragma once
#include <istream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
#include "ListStack.h"
#include "BinaryTree.h"
using namespace std;

void ShowNodeData(char data)
{
	if ('0' <= data && data <= '9')
		printf("%d ", data - '0');
	else
		printf("%c ", data);

}
class ExpressTree
{
private:
	string expstr;
	BTreeNode<char>* eTree;
public:
	ExpressTree(string exp) : expstr(exp)
	{
		ListStack<BTreeNode<char>*> stack;
		BTreeNode<char>* node;

		int explen = expstr.length();
		int i;

		for (i = 0; i < explen; i++)
		{
			node = new BTreeNode<char>;

			if (isdigit(expstr[i]))
			{
				node->SetData(expstr[i]);
			}
			else
			{
				node->MakeRightSubTree(stack.SPop());
				node->MakeLeftSubTree(stack.SPop());
				node->SetData(expstr[i]);
			}
			stack.SPush(node);
		}

		eTree = stack.SPop();
	}

	BTreeNode<char>* GetTreeNode()
	{
		return eTree;
	}

	int EvalutionExpTree(BTreeNode<char>* node)
	{
		int op1, op2;

		if (node->GetLeftSubTree() == nullptr && node->GetRightSubTree() == nullptr)
		{
			return node->GetData() - '0';
		}
			
		op1 = EvalutionExpTree(node->GetLeftSubTree());
		op2 = EvalutionExpTree(node->GetRightSubTree());

		switch (node->GetData())
		{
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}

		return 0;
	}

	void ShowPrefixTypeExp()
	{
		eTree->PreorderTraverse(ShowNodeData);
	}

	void ShowInfixTypeExp()
	{
		eTree->InorderTraverse(ShowNodeData);
	}

	void ShowPostfixTypeExp()
	{
		eTree->PostorderTraverse(ShowNodeData);
	}
};