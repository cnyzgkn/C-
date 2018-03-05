#include <iostream>
#include <vector>
#include <algorithm>

// count the number of variables > 4 in a std::vector
//1. function
bool gt4(int x)
{
	return (x > 4);
}

//2. functor
struct GT4
{
	bool operator() (int x)
	{
		return (x > 4);
	}
};

void main()
{
	std::vector<int> v{2,5,8,3,1,6}; //C++ 11 initializer_list
	std::cout << "function gt4 " << count_if(v.begin(), v.end(), gt4) << std::endl;
	std::cout << "functor GT4 " << count_if(v.begin(), v.end(), GT4()) << std::endl;
	//3. lambda [捕获列表] (参数列表) -> 返回类型 {函数体}
	std::cout << "lambda " << count_if(v.begin(), v.end(), [](int x) {return (x > 4);}) << std::endl;
	//4. closure: 子函数可以使用父函数中的局部变量 
	//count the number of variables > k in a std::vector
	int k = 4;
	std::cout << "closure " << count_if(v.begin(), v.end(), [k](int x) {return (x > k);}) << std::endl;
}