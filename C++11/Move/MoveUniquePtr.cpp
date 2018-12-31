#include <string>
#include <memory>
#include <iostream>

using namespace std;

unique_ptr<string> TransferOwnership(unique_ptr<string>& origString)
{
	return std::move(origString);
}

int main()
{
	unique_ptr<string> opString1(new string("hello"));
	cout << "oldString content is " << *(opString1.get()) << " address is " << opString1.get() << endl;
	unique_ptr<string> opString2 = TransferOwnership(opString1);
	cout << "newString content is " << *(opString2.get()) << " address is " << opString2.get() << endl;
	cout << "oldString content is " << *(opString1.get()) << " address is " << opString1.get() << endl;

	return 0;
}