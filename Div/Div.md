# 除法运算
在当前工程中创建Div方法，实现输入两个int类型的参数，并返回两个数的商，其中需要对除数进行判定，若是除数为零的情况则通过代码显示相关的错误信息。

---

## 实现方法
* 首先在当前工程创建Div的头文件，在其中实现函数方法的声明。  
![div01](https://gitee.com/cillebokin/temporary-pictures/raw/master/div01.png)  

* 在当前工程的.cpp文件中实现函数方法。由于除数不能为零，因此利用try catch语句，当除数为零时抛出异常，并显示错误信息，以结束函数，若输入的参数符合规范，则返回，两个int的商。  
![div02](https://gitee.com/cillebokin/temporary-pictures/raw/master/div02.png)  


* 在主函数中调用该方法，若返回值不为NULL，则打印输出返回值。  
![div03](https://gitee.com/cillebokin/temporary-pictures/raw/master/div03.png)  

* 编译运行，成功调用该方法。
![div04](https://gitee.com/cillebokin/temporary-pictures/raw/master/div04.png)  
![div05](https://gitee.com/cillebokin/temporary-pictures/raw/master/div05.png)  

* 调用该库文件的作用为，输入两个int类型的整数，返回两数的商。  
调用方法：`int Div(int, int)`  

---

## Div方法的头文件代码  
```
#ifndef _DIV_H_
#define _DIV_H_

int Div(int, int);

#endif
```

## Div方法的实现代码  
```
int Div(int a, int b)
{
	try
	{
		if (0 == b)
		{
			throw - 1;
		}
	}
	catch (int e)
	{
		printf("Divisor cann't be zero(throwNo.%d)！\n", e);
		return NULL;
	}
	return (a / b);
}
```

## Div方法的调用代码
```
int main()
{
	//Input two numbers
	int OperatorNum1, OperatorNum2;
	printf("Plesase input two integer numbers and press enter:(Such as 1,2)\n");
	scanf("%d, %d", &OperatorNum1, &OperatorNum2);

	//Function Divide
	int div = Div(OperatorNum1, OperatorNum2);
	if (NULL != div)
	{
		printf("%d / %d = %d\n", OperatorNum1, OperatorNum2, div);
	}

	return 0;
}
```