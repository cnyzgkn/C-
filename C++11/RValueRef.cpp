
int returnVal()
{
	int tmp = 1;
	return tmp;
}

int main(int argc, char const *argv[])
{
	int &&i = 1; // i = 1
	const int num = 2;
	i = num; // i = 2


	int a = returnVal();
	int &b = a;
	//int &c = returnVal(); //左值引用无法绑定到右值
	const int &d = returnVal(); //const左值引用可以绑定到右值但d的值无法变化

	return 0;
}