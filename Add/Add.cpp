#include "Add.h"
#include <iostream>

using namespace std;
int Add(int a, int b, int* sum)
{
	if (a > -1 && b > -1 && b > INTMAX - a)
	{
		return -1;
	}
	else if (a < 0 && b < 0 && b < INTMIN - a)
	{
		return -1;
	}
	else
	{
		*sum = (a + b);
		return 0;
	}
}
