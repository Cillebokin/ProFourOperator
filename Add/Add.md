#VS平台下关于静态库的创建与使用
## 静态库简介  
静态库是在链接阶段会将汇编成成的目标文件.o与引用到的库一起链接打包到可执行文件中，因此对应的链接方式称为静态链接，静态库可以简单看成是一组目标文件的集合，即很多目标文件经过压缩打包后形成的一个文件。  
* 静态库对函数库的链接是放在编译时期完成的。  
* 程序在运行时与函数库再无瓜葛，移植方便。  
* 浪费空间和资源，因为所有相关的目标文件与牵涉到的函数库被链接成一个可执行文件。  

---

## 静态库的创建流程
* 静态库的创建会生成一个.lib文件，供其他工程调用
* 首先在工程中，点击文件 - 新建 - 项目。  
![staticLib01](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib01.png)  

* 为库起名称，并指定好工程位置，确定后点击下一步。  
![staticLib02](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib02.png)   
![staticLib03](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib03.png)   

* 将应用程序类型设定为静态库，点击确定。  
![staticLib04](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib04.png)   

* 为此工程添加.h文件和.cpp文件。  
![staticLib05](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib05.png)  
![staticLib06](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib06.png)  
![staticLib07](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib07.png)  
![staticLib08](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib08.png)  

* 为库文件编写头文件的内容。  
![staticLib09](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib09.png)  

* 为库文件编写cpp文件的内容。  
![staticLib10](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib10.png)  

* 随后点击生成 - 生成解决方案/重新生成解决方案，即可生成Add.lib的库文件。  
![staticLib11](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib11.png)  
![staticLib12](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib12.png)  

* 调用该库文件的作用为，输入两个int类型的整数，返回两数的和。  
调用方法：`int Add(int, int)`

---

## 静态库的调用方法  

* 在需要调用该库文件的工程中，右击工程，选择属性，进行相关配置。  
![staticLib13](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib13.png)  
![staticLib14](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib14.png)  

* 在配置属性 - VC++目录中，包含目录为库文件的Add.h头文件所在的目录，而库目录为Add.lib库文件所在的目录，点击确定。  
![staticLib15](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib15.png)  

* 在配置属性 - 链接器 - 输入中，在附加依赖项中添加要调用的库，输入Add.lib，点击确定即可。  
![staticLib16](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib16.png)  

* 配置完成后，在需要调用库的工程中便可以引用头文件，并调用库的功能。  
![staticLib17](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib17.png)  

* 编译运行后，成功调用库。  
![staticLib18](https://gitee.com/cillebokin/temporary-pictures/raw/master/staticLib18.png)  

---

## Add库的头文件代码
```
#ifndef _ADD_H_
#define _ADD_H_

int Add(const int, const int);

#endif
```
## Add库的cpp代码
```
#include "Add.h"

int Add(int a, int b)
{
	return (a + b);
}
```


---

## 小结  
由于静态库是在编译过程中静态地被链接到最终的可执行文件当中，占据了部分内存空间，在程序执行时也同库函数再无关系，由此可见静态库在程序的使用中并不灵活，不利于项目后续的开发工作，而动态库的概念则解决了静态库的相关问题。