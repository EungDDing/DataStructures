#include <iostream>
#include "Calculator.h"
using namespace std;

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	Calculate cal1(exp1);
	Calculate cal2(exp2);
	Calculate cal3(exp3);

	cout << cal1.exp << " = " << cal1.EvalInfixExp() << endl;
	cout << cal2.exp << " = " << cal2.EvalInfixExp() << endl;
	cout << cal3.exp << " = " << cal3.EvalInfixExp() << endl;
	return 0;
}