#include <iostream>
#include <atlstr.h>
#include <windows.h>
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Div.h"

using namespace std;

int Div(int a, int b, int *div)
{

	if (b == 0)
	{
		return 1;
	}
	else if (a == INTMIN && b == -1)
	{
		return -1;
	}
	else
	{
		*div = (a / b);
		return 0;
	}

}
/*
LoadMul findMulDll(HINSTANCE hmod)
{
	hmod = LoadLibrary("Mul.dll");

	LoadMul Load_mul = NULL;
	Load_mul = (LoadMul)GetProcAddress(hmod, "Mul");
	return Load_mul;
}
*/
LoadMul findMulDll(HINSTANCE hmod, CString dllName, CString dllFunName)
{
	hmod = LoadLibrary(dllName);
	if (hmod == INVALID_HANDLE_VALUE)
	{
		printf("error\n");
		return NULL;
	}

	LoadMul Load_mul = NULL;
	Load_mul = (LoadMul)GetProcAddress(hmod, dllFunName);
	if (NULL == Load_mul)
	{
		printf("error\n");
		return NULL;
	}
	else
	{
		return Load_mul;
	}
}

int main()
{
	//Input two numbers
	int OperatorNum1, OperatorNum2, flag;
	cout << "Plesase input two integer numbers and press enter:" << endl;
	cin >> OperatorNum1 >> OperatorNum2;

	//Function Add
	int sum;
	flag = Add(OperatorNum1, OperatorNum2, &sum);
	if (flag == 0)
	{
		cout << OperatorNum1 << " + " << OperatorNum2 << " = " << sum << endl;
	}
	else
	{
		cout << "The range of numbers was beyond borders!" << endl;
	}

	
	//Function Subtract
	int sub;
	flag = Sub(OperatorNum1, OperatorNum2, &sub);
	if (flag == 0)
	{
		cout << OperatorNum1 << " - " << OperatorNum2 << " = " << sub << endl;
	}
	else
	{
		cout << "The range of numbers was beyond borders!" << endl;
	}

	
	//Function Multiply
	int mul;
	HINSTANCE hmod = NULL;
	LoadMul Load_mul = findMulDll(hmod, "Mul.dll", "Mul");
	flag = Load_mul(OperatorNum1, OperatorNum2, &mul);
	if (flag == 0)
	{
		cout << OperatorNum1 << " * " << OperatorNum2 << " = " << mul << endl;
	}
	else
	{
		cout << "The range of numbers was beyond borders!" << endl;
	}
	FreeLibrary(hmod);

	
	//Function Divide
	int div;
	flag = Div(OperatorNum1, OperatorNum2, &div);
	if (flag == -1)
	{
		cout << "The range of numbers was beyond borders!" << endl;
	}
	else if (flag == 1)
	{
		cout << "Divisor can't be zero!" << endl;
	}
	else
	{
		cout << OperatorNum1 << " / " << OperatorNum2 << " = " << div << endl;
	}
	

	return 0;
}