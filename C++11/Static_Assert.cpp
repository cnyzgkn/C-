#include <cassert>
#include <string>

using namespace std;

template<class T, class U>
void bitCopy1(T &a, U &b)
{
	assert(sizeof(a) == sizeof(b));  // error detected in run-time
	memcpy(&a, &b, sizeof(b));
};

#define assert_static(e)\
  do{\
  	enum {assert_static_ = 1/(e)};\
  }while(0)   //C++11之前使用静态断言，用除0的方法判断

template<class T, class U>
void bitCopy2(T &a, U &b)
{
	assert(sizeof(a) == sizeof(b));  // error detected in run-time
	memcpy(&a, &b, sizeof(b));
};

template<class T, class U>
void bitCopy3(T &a, U &b)
{
	static_assert(sizeof(a) == sizeof(b), "a and b don't have identical size!");  // error detected in compiler-time
	memcpy(&a, &b, sizeof(b));
};

int main(int argc, char const *argv[])
{
	double a;
	int b = 1;

	bitCopy1(a, b);

	bitCopy2(a, b);

	bitCopy3(a, b);

	return 0;
}