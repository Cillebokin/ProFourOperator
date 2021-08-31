#ifndef _SUB_H_
#define _SUB_H_

#ifdef _WINDLL
#define DLL_API extern "C" __declspec(dllexport)
#else
#define DLL_API extern "C" __declspec(dllimport)
#endif

#define INTMAX 2147483647
#define INTMIN -2147483647-1

DLL_API int Sub(int, int, int*);

#endif