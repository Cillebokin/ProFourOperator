#include "stdafx.h"
#include "CppUnitTest.h"
#include "windows.h"
#include <atlstr.h>
#include <iostream>

#include "../Add/Add.h"
#include "../Sub/Sub.h"
#include "../Mul/Mul.h"
#include "../Div/Div.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod_Add)
		{
			//Cite ini file to test
			CString SectionName = "Section";
			CString SectionNum;
			int ANum, BNum, SumNum, add, flag;

			int AllCount = GetPrivateProfileInt("Number", "Num", 0, "../Add/Add.ini");
			for (int i = 1; i <= AllCount; i++)
			{
				SectionNum.Format(_T("%d"), i);
				SectionName += SectionNum;
				ANum = GetPrivateProfileInt(SectionName, "A", 0, "../Add/Add.ini");
				BNum = GetPrivateProfileInt(SectionName, "B", 0, "../Add/Add.ini");
				SumNum = GetPrivateProfileInt(SectionName, "Sum", 0, "../Add/Add.ini");

				flag = Add(ANum, BNum, &add);
				if (flag == 0)
				{
					Assert::AreEqual(SumNum,add);
				}
				else if (flag == -1)
				{
					Assert::AreEqual(SumNum, 0);
				}
				
			}
		}
		
		TEST_METHOD(TestMethod_Sub)
		{
			//Cite ini file to test
			CString SectionName = "Section";
			CString SectionNum;
			int ANum, BNum, SubNum, sub, flag;

			int AllCount = GetPrivateProfileInt("Number", "Num", 0, "../Sub/Sub.ini");
			for (int i = 1; i <= AllCount; i++)
			{
				SectionNum.Format(_T("%d"), i);
				SectionName += SectionNum;
				ANum = GetPrivateProfileInt(SectionName, "A", 0, "../Sub/Sub.ini");
				BNum = GetPrivateProfileInt(SectionName, "B", 0, "../Sub/Sub.ini");
				SubNum = GetPrivateProfileInt(SectionName, "Sub", 0, "../Sub/Sub.ini");

				flag = Sub(ANum, BNum, &sub);
				if (flag == 0)
				{
					Assert::AreEqual(SubNum, sub);
				}
				else if (flag == -1)
				{
					Assert::AreEqual(SubNum, 0);
				}
			}
		}
		
		TEST_METHOD(TestMethod_Mul)
		{
			//Cite ini file to test
			CString SectionName = "Section";
			CString SectionNum;
			int ANum, BNum, MulNum, mul, flag;

			int AllCount = GetPrivateProfileInt("Number", "Num", 0, "../Mul/Mul.ini");
			for (int i = 1; i <= AllCount; i++)
			{
				SectionNum.Format(_T("%d"), i);
				SectionName += SectionNum;
				ANum = GetPrivateProfileInt(SectionName, "A", 0, "../Mul/Mul.ini");
				BNum = GetPrivateProfileInt(SectionName, "B", 0, "../Mul/Mul.ini");
				MulNum = GetPrivateProfileInt(SectionName, "Mul", 0, "../Mul/Mul.ini");

				flag = Mul(ANum, BNum, &mul);
				if (flag == 0)
				{
					Assert::AreEqual(MulNum, mul);
				}
				else if (flag == -1)
				{
					Assert::AreEqual(MulNum, 0);
				}
			}
		}
		
		TEST_METHOD(TestMethod_Div)
		{
			//Cite ini file to test
			CString SectionName = "Section";
			CString SectionNum;
			int ANum, BNum, DivNum, div, flag;

			int AllCount = GetPrivateProfileInt("Number", "Num", 0, "../Div/Div.ini");
			for (int i = 1; i <= AllCount; i++)
			{
				SectionNum.Format(_T("%d"), i);
				SectionName += SectionNum;
				ANum = GetPrivateProfileInt(SectionName, "A", 0, "../Div/Div.ini");
				BNum = GetPrivateProfileInt(SectionName, "B", 0, "../Div/Div.ini");
				DivNum = GetPrivateProfileInt(SectionName, "Div", 0, "../Div/Div.ini");

				flag = Div(ANum, BNum, &div);
				if (flag == 0)
				{
					Assert::AreEqual(DivNum, div);
				}
				else if (flag == -1)
				{
					Assert::AreEqual(DivNum, 0);
				}
			}
		}
		/*
		TEST_METHOD(TestMethod_findMulDll)
		{
			HINSTANCE hmod = NULL;
			//LoadMul Load_mul = findMulDll(hmod, "Mul.dll", "Mul");
			LoadMul Load_mul = findMulDll(hmod);
			int mul = Load_mul(3,4);
			Assert::AreEqual(12, 12);
			FreeLibrary(hmod);
		}
		*/
	};
}