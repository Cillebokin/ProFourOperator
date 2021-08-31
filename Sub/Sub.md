#VS平台下关于使用导出语句生成和使用动态库
## 动态库简介  
由于静态库浪费空间是一个明显的问题，此外静态库对程序的更新、部署和发布会带来麻烦。如果静态库更新了，所使用它的应用程序都需要重新编译、发布给用户。而动态库在程序编译时不会被链接到目标代码中，而是程序在运行时才被载入，<u>不同的应用程序如果调用相同的库，那么在内存里只需要有一份该共享库的实例，</u>规避了空间浪费的问题，也解决了程序更新、部署和发布带来的麻烦，仅需更新动态库即可。  
* 动态库把对一些库函数的链接载入推迟到程序运行时。  
* 可以实现进程之间的资源共享。  
* 将程序升级变得更简单。  
* 可做到链接载入完全由程序员在代码中控制。  
* 不需要打包工具，直接使用编译器即可创建动态库。  

其中创建动态库的关键是导出函数，Dll中导出函数的声明有两种方式：  
* 在函数声明中加上__declspec(dllexport);  
* 采用模块定义(.def)文件声明，其为链接器提供了有关被链接程序的导出、属性及其他方面的信息。  
而动态库的调用也分为静态加载和动态两种方式，动态加载是指在生成的可执行文件时不将所有程序用到的函数链接到一个文件，因为有许多函数在操作系统带的dll文件中，当程序运行时直接从操作系统中找。而静态加载则是把所有用到的函数全部链接到exe文件中，把所有代码和数据都复制到本模块中，运行时就不需要库了。  
此处选择导出语句生成库文件，以及静态加载。  

---

## 使用导出语句创建动态库
* 选择添加 - 新建项目。  
![staticLib01](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_01.png)  

* 添加库的名称，指定路径并选择确定后，点击下一步。  
![staticLib02](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_02.png)  
![staticLib03](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_03.png)  

* 选择DLL以及空项目，点击完成。  
![staticLib04](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_04.png)  

* 工程创建完成后，添加.h文件和.cpp文件。  
![staticLib05](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_05.png)  
![staticLib06](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_06.png)  
![staticLib07](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_07.png)  

* 编写.cpp文件的函数库功能。  
![staticLib08](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_10.png)  

* 在.h头文件中为函数添加导出语句。  
![staticLib09](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_09.png)  

* 点击生成，选择生成解决方案。  
![staticLib10](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_11.png)  

* 成功生成Sub.dll和Sub.lib文件。  
![staticLib11](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_12.png)  

* 调用该库文件的作用为，输入两个int类型的整数，返回两数的差。  
调用方法：`int Sub(int, int)`  

---

##动态库的静态加载  
* 在需要调用库的工程中，右击选择属性，修改相关配置文件。  
![staticLib12](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_13.png)  

* 在配置属性 - VC++中，包含目录用于添加库所在的头文件路径，库目录用于添加库所在的库文件路径。
![staticLib13](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_14.png)    

* 在链接器 - 输入中的附加依赖项，添加所要调用的Lib文件的文件名。
![staticLib14](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_15.png)  

* 在需要调用库的工程中，包含头文件，并编写调用库函数的功能。  
![staticLib15](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_16.png)  

* 编译运行后，成功调用库的功能。
![staticLib16](https://gitee.com/cillebokin/temporary-pictures/raw/master/dynamicLib1_17.png)  

---

## Sub库的头文件代码
```
#ifndef _SUB_H_
#define _SUB_H_

#ifdef _WINDLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

DLL_API int Sub(const int, const int);

#endif
```
## Sub库的cpp文件代码
```
#include "Sub.h"

int Sub(const int a, const int b)
{
	return (a - b);
}
```

---

##小结
动态库的静态加载将所有的代码和数据都链接到最终的可执行文件当中，因此在运行的过程中就不在需要.lib库了。  