#ifndef _DIV_H_
#define _DIV_H_

#define INTMAX 2147483647
#define INTMIN -2147483647-1

typedef int(*LoadMul)(int, int, int*);
int Div(int, int, int*);
LoadMul findMulDll(HINSTANCE);
//LoadMul findMulDll(HINSTANCE, CString, CString);

#endif