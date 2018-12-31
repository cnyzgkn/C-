#include <iostream>

class MyString
{
public:
	MyString(const char* str = NULL);
	MyString(const MyString& other);
	MyString(MyString&& other);
	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other);
	void print();
	~MyString();

private:
	char* m_data;
	size_t m_length;
};

MyString::MyString(const char* str)
{
	std::cout << "MyString constructor" << std::endl;
	if(str)
	{
		m_length = strlen(str);
		m_data = new char[m_length+1];
		strcpy(m_data, str);
	}else
	{
		m_length = 0;
		m_data = new char[1];
		*m_data = '\0';
	}
}

MyString::MyString(const MyString& other)
{
	std::cout << "MyString copy constructor" << std::endl;
	m_length = other.m_length;
	m_data = new char[m_length]; 
	strcpy(m_data, other.m_data);
}

MyString::MyString(MyString&& other)
{
	std::cout << "MyString move constructor" << std::endl;
	m_data = other.m_data;
	other.m_data = NULL;
	m_length = other.m_length;
	other.m_length = 0;
}

MyString& MyString::operator=(const MyString& other)
{
	std::cout << "MyString assignment operator" << std::endl;
	if(this == &other)
	 	return *this;

	delete [] m_data;
	m_length = other.m_length;
	m_data = new char[m_length+1]; 
	strcpy(m_data, other.m_data);
	return *this;
}

MyString& MyString::operator=(MyString&& other)
{
	std::cout << "MyString move operator" << std::endl;
	if(this == &other)
	 	return *this;

	delete [] m_data;
	m_data = other.m_data;
	other.m_data = NULL;
	m_length = other.m_length;
	other.m_length = 0;
	return *this;
}

MyString::~MyString()
{
	std::cout << "MyString destructor" << std::endl;
	delete [] m_data;
	m_length = 0;
}

void MyString::print()
{
	std::cout << m_data << std::endl;
}

void printMyString(MyString str)
{
	str.print();
}

MyString initMyString(const char* str)
{
	return MyString(str);
}

void main()
{
	MyString *str1 = new MyString("hello");
	str1->print();

	MyString str2 = *str1;
	delete str1;
	str2.print();
	
	MyString str3 = initMyString("world");
	str3.print();

	MyString str4 = std::move(str3);
	str4.print();
}