
int a;
const int b = 0;// equal to const static int b = 0 so need NOT use extern;

//编译器通常不为普通const常量分配存储空间，而是将它们保存在符号表中，
//这使得它成为一个编译期间的常量，没有了存储与读内存的操作，使得它的效率也很高。
//static与const组合：在每个文件都需要定义一份静态全局变量。
//extern与const组合:只需要定义一份全局变量，多个文件共享。

