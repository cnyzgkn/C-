#include <iostream>

void int2CharReinterpretCast()
{
    std::cout << "int2CharReinterpretCast" << std::endl;
    int* pi = nullptr;
    char* pc = reinterpret_cast<char*>(pi);
    std::cout << "pi type == " << typeid(*pi).name() << std::endl;
    std::cout << "pc type == " << typeid(*pc).name() << std::endl;
}

unsigned short Hash(void* p)
{
    unsigned int val = reinterpret_cast<unsigned int>( p );
    return ( unsigned short )( val ^ (val >> 16));
}

void printHash()
{
    std::cout << "printHash" << std::endl;
    int a[20];
    for ( int i = 0; i < 20; i++ )
      std::cout << Hash( a + i ) << std::endl;
}

int main()
{
    int2CharReinterpretCast();
    printHash();
}