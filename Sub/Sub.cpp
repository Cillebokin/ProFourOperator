#include "Sub.h"

int Sub(int a, int b, int* sub)
{
	if ((a > 0) && (b < 0) && (a > INTMAX + b))
	{
		return -1;
	}
	else if ((a < 0) && (b > 0) && (a < INTMIN + b))
	{
		return -1;
	}
	else
	{
		*sub = (a - b);
		return 0;
	}
}