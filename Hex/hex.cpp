#include <sstream>
#include <iostream>
#include <string>

void main()
{
	unsigned char R = 92;
	unsigned char G = 92;
	unsigned char B = 255;
	std::cout << "R == " << std::hex << (int)R << " G == " << std::hex << (int)G << " B == " << std::hex << (int)B << std::endl;


	int result = ((int)R)*0x10000 + ((int)G)*0x100 + ((int)B);
	std::cout << "result == " << result << std::endl;
	std::cout << "result hex == " << std::hex << result << std::endl;
}
