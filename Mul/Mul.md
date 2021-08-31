# VS平台下关于使用模块定义生成和使用动态库

## 模块定义文件声明
除了利用导出语句生成动态库之外，另外一种方式是采用模块定义(.def)文件声明，.def文件为链接器提供了有关被链接程序的导出、属性及其他方面的信息。  
此外，动态库的调用也分为静态加载和动态加载，动态加载是指在生成可执行文件时不将所有程序用到的函数链接到一个文件，因为有许多函数在操作系统带的dll文件中，当程序运行时直接从操作系统中找，前文已描述了使用导出语句生成动态库并做静态加载，此处使用模块定义文件生成动态库并采用动态加载的方式调用库。

---

## 使用模块定义生成动态库

* 首先创建库的工程。   
![dynamicLib2_01](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_01.png)

* 输入库的名称和路径并点击确定，选择下一步。  
![dynamicLib2_02](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_02.png)  
![dynamicLib2_03](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_03.png)  

* 选择DLL和空项目，点击完成。  
![dynamicLib2_04](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_04.png)  

* 在库的工程中添加.h文件和.cpp文件，并编写相关的库函数内容。  
![dynamicLib2_05](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_05.png)  
![dynamicLib2_06](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_06.png)  
![dynamicLib2_07](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_07.png)  
![dynamicLib2_09](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_09.png)  
![dynamicLib2_10](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_10.png)  

* 利用模块定义文件生成动态库，则需要再额外添加.def文件
![dynamicLib2_11](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_11.png)  
![dynamicLib2_12](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_12.png)  

* 此处编写.def文件，其中文件第一行引号中填写库项目的名称即可，EXPORTS下面列出要生成的函数名称，格式：名称 @序号，若只有一个函数则可以不填写序号。  
![dynamicLib2_13](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_13.png)  

* 编写完成后，无需导出语句即可生成动态库，点击生成 - 生成解决方案，便能完成动态库的创建。    
![dynamicLib2_14](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_14.png)  
![dynamicLib2_15](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_15.png)  

* 调用该库文件的作用为，输入两个int类型的整数，返回两数的乘积。  
调用方法：`int Mul(int, int)`

---

## 动态库的动态加载调用
* 通过同样的方式进行相关配置，在需要调用该库的工程中，右击选择属性，配置属性 - VC++中，包含目录中添加库的头文件目录，库目录中添加库文件所在的目录。  
![dynamicLib2_16](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_16.png)  
![dynamicLib2_17](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_17.png)  

* 链接器 - 输入中，附加依赖项中输入库的名称后点击确定即可。  
![dynamicLib2_18](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_18.png)  

* 在要调用库的工程中，编写相关内容实现库的动态加载。  
![dynamicLib2_19](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_19.png)  
![dynamicLib2_20](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_20.png)  
![dynamicLib2_21](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_21.png)  

* 首先定义一个函数指针用于指向调用库的函数，声明函数findMulDll（），起作用就是加载库的dll文件，并返回指向库函数的函数指针。需要理解调用动态库主要用到三个函数，加载LoadLibrary、调用GetProcAddress、释放FreeLibrary。  
![dynamicLib2_22](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_22.png)  
![dynamicLib2_23](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_23.png)  
![dynamicLib2_24](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_24.png)  

* 在动态调用的过程中，可能会遇到如图，const char*类型实参与LPCWSTR类型的形参不兼容的问题，这是由于字符集的问题，右击选择属性，在配置属性 - 常规中，将字符集选择为使用多字节字符集，点击确定，参数类型就不会报错。  
![dynamicLib2_25](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_25.png)  
![dynamicLib2_26](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_26.png)  
![dynamicLib2_27](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_27.png)  

* 编译运行后，成功调用库函数。  
![dynamicLib2_28](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib2_28.png)  

---


## Mul库的.h文件代码
```
#ifndef _Mul_H_
#define _Mul_H_

extern "C" int Mul(int, int);

#endif
```

## Mul库的.cpp文件代码
```
#include "Mul.h"

int Mul(int a,int b)
{
	return (a * b);
}
```

## Mul库的.def文件代码
```
LIBRAR "Mul"
EXPORTS
    Mul @1
```

## Mul库的动态调用方法
```
//声明函数指针，和加载函数的声明
typedef int(*LoadMul)(int, int);
LoadMul findMulDll(HINSTANCE);

//findMulDll()的实现
LoadMul findMulDll(HINSTANCE hmod)
{
	hmod = LoadLibrary("Mul.dll");
	if (hmod == INVALID_HANDLE_VALUE)
	{
		printf("error\n");
		return NULL;
	}

	LoadMul Load_mul = NULL;
	Load_mul = (LoadMul)GetProcAddress(hmod, "Mul");
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

//动态调用方法
int main()
{
	//Input two numbers
	int OperatorNum1, OperatorNum2;
	printf("Plesase input two integer numbers and press enter:(Such as 1,2)\n");
	scanf("%d, %d", &OperatorNum1, &OperatorNum2);

	//Function Multiply
	HINSTANCE hmod = NULL;
	LoadMul Load_mul = findMulDll(hmod);
	int mul = Load_mul(OperatorNum1, OperatorNum2);
	printf("%d * %d = %d\n", OperatorNum1, OperatorNum2, mul);
	FreeLibrary(hmod);

	return 0;
}
```

---

## 小结  

动态库程序包含.lib文件和.dll文件，.lib文件是必需在编译期就连接到应用程序中的，dll文件是运行期才会被调用的，如果有dll文件，那么对应的lib文件一般是一些索引信息，具体的实现在dll文件中，如果只有lib文件，那么这个lib文件是静态编译出来的，索引和实现都在其中。  