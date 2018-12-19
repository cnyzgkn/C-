#include <iostream>

using namespace std;

class HasPtrMem
{
public:
	HasPtrMem() : d(new int(0))
	{
		cout << "Construct " << ++n_cstr << endl;
	}

	HasPtrMem(const HasPtrMem& other) : d(new int(*other.d))  //深拷贝
	{
		cout << "Copy Construct " << ++n_cptr << endl;
	}

	HasPtrMem(const HasPtrMem&& other) : d(other.d) //浅拷贝
	{
		cout << "Move Construct " << ++n_mvtr << endl;
	}

	~HasPtrMem()
	{
		delete d;
		cout << "Destruct " << ++n_dstr << endl;
	}

	int *d;
	static int n_cstr;
	static int n_dstr;
	static int n_cptr;
	static int n_mvtr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;


HasPtrMem getTemp()
{
	HasPtrMem temp;
	cout << "Resource from " << __func__ << " " << hex << temp.d << endl;
	return temp;
}

int main(int argc, char const *argv[])
{
	HasPtrMem a;
	HasPtrMem b = a;

	HasPtrMem c = getTemp();
	cout << "Resource from " << __func__ << " " << hex << c.d << endl;

	return 0;
}