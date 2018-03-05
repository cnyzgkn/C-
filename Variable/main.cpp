#include <iostream> 

//C编译后生成_c_func,C++编译后生成_c_func_argument之类
//方法1: extern "C" 包含c头文件
extern "C"
{
	#include "c_header.h"	
}

//方法1: extern "C" 声明c函数
//extern "C" void c_func();

extern void increGlobalStaticVal(); //声明函数时extern可省略
extern void increGlobalcVal(); 

int localStaticVal()
{
	 //局部全局变量：函数退出时不会被清除出调用栈
	 //1.该变量在全局数据区分配内存而非普通函数内局部变量分配的栈内存
     //2.在程序执行到该对象的声明处时被首次初始化，即以后的函数调用不再进行初始化；
     //3.在声明处初始化，如果没有显式初始化，会被程序自动初始化为0；
     //4.始终驻留在全局数据区直到程序运行结束，但其作用域为局部作用域，当定义它的函数或语句块结束时，其作用域随之结束；
	static int localStaticVal = 10;
	return ++localStaticVal;
}

void staticFunc()
{
	std::cout << "staticFunc() in main.cpp" << std::endl;  
}

//1.volatile声明的类型变量表示可以被某些编译器未知的因素更改，比如操作系统、硬件或者其它线程等
//2.访问寄存器的速度要快过RAM，所以编译器都会作减少存取外部RAM的优化。
//3.遇到volatile，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问 

int main(void)  
{  
	//静态全局变量在main.cpp中不可见
	//extern int globalStaticVal;//extern variable must be declared before use
    //std::cout << "globalStaticVal == " << globalStaticVal << std::endl;  
    //increGlobalStaticVal();   

	//extern作用：不与C连用时
    //1.该变量或函数可在本模块和其它模块中使用
    //2.编译阶段虽然在本模块中找不到此变量或函数的定义但不会报错，会在连接时从别的模块找到
    extern int globalVal; //声明变量时extern不可省略，若省略，则int globalVal在本文件定义一个未初始化的变量。
    //全局变量可在文件中共享
    std::cout << "globalVal == " << globalVal << std::endl;  
    increGlobalcVal();   

    //多次调用localStaticVal()其值会保留
    for(int i = 0; i < 5; i++)
    {
    	std::cout << "localStaticVal == " << localStaticVal() << std::endl;
    }

    staticFunc();

    c_func();

    return 0;  
}  
