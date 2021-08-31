#include "Mul.h"

int Mul(int a, int b, int* mul)
{
	if (a > 0 && b > 0 && b > (INTMAX / a))
	{
		return -1;
	}
	else if (a < 0 && b < 0 && b < (INTMAX / a))
	{
		return -1;
	}
	else if (a > 0 && b < 0 && b < (INTMIN / a))
	{
		return -1;
	}
	else if (a < 0 && b > 0 && b > (INTMIN / a))
	{
		return -1;
	}
	else
	{
		*mul = (a * b);
		return 0;
	}
}