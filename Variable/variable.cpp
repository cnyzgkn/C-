#include <iostream>  

//静态全局变量
//1.在全局数据区分配内存
//2.在声明它的整个文件都是可见的，而在文件之外是不可见的
//3.不同文件使用不会发生冲突 
//4.static和const
static int globalStaticVal = 20; 

//静态函数
//1.静态函数不能被其它文件所用；
//2.其它文件中可以定义相同名字的函数，不会发生冲突；
static void staticFunc()
{
	std::cout << "staticFunc() in variable.cpp" << std::endl;  
}

//全局变量
//1.在全局数据区分配内存
//2.在其它文件中也是可见的
extern int globalVal = 30; //定义变量时extern可省略
extern int globalVal;//这是声明，系统不给变量分配空间，故link时会报error LNK2001: unresolved external symbol错误
  
void increGlobalStaticVal()  
{  
    std::cout << "globalStaticVal == " << ++globalStaticVal << std::endl;  
}  

void increGlobalcVal()  
{  
    std::cout << "globalVal == " << ++globalVal << std::endl;  
}  