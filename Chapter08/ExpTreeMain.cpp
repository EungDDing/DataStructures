#include <iostream>
#include "ExpressTree.h"

int main(void)
{
	string exp = "123*+4+";

	ExpressTree tree(exp);

	tree.ShowPrefixTypeExp();
	cout << endl;

	tree.ShowInfixTypeExp();
	cout << endl;

	tree.ShowPostfixTypeExp();
	cout << endl;

	cout << tree.EvalutionExpTree(tree.GetTreeNode());
}