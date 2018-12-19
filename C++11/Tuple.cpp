#include <tuple>
#include <string>
#include <iostream>

using namespace std;

typedef tuple<int, int, string> valTuple;


int main(int argc, char const *argv[])
{
	valTuple curTuple(0, 1, "hello!");
	cout << get<0>(curTuple) << endl;
	cout << get<1>(curTuple) << endl;
	cout << get<2>(curTuple) << endl;

	//cout << get<int>(curTuple) << endl;  //error
	cout << get<string>(curTuple) << endl;

	return 0;
}


