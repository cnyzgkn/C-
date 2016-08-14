#include <stdio.h>
#include <string.h>
#include <iostream>

class String
{
public:
	String(const char* str = NULL);
	String(const String& other);
	virtual ~String();
	String& operator=(const String& other);
	bool operator==(const String& other) const;
	char& operator[](const int i);
	const char& operator[](const int i) const;
	void printSelf() { std::cout << "I am String " << m_str << std::endl; }

private:
	char* m_str;
};

String::String(const char* str)
{
	if(str == NULL)
	{
		m_str = NULL;
	}else
	{
		m_str = new char[strlen(str)+1];
		strcpy(m_str, str);
	}
}

String::String(const String& other)
{
	if(other.m_str == NULL)
	{
		m_str = NULL;
	}else
	{
		m_str = new char[strlen(other.m_str)+1];
		strcpy(m_str, other.m_str);
	}
}

String::~String()
{
	delete [] m_str;
}

String& String::operator=(const String& other)
{
	if(this == &other)
		return *this;

	if(other.m_str == NULL)
	{
		m_str = NULL;
	}else
	{
		m_str = new char[strlen(other.m_str)+1];
		strcpy(m_str, other.m_str);
	}

	return *this;
}

bool String::operator==(const String& other) const
{
	if(m_str == NULL | other.m_str == NULL)
		return false;

	if(strcmp(m_str, other.m_str))
		return false;

	return true;
}

char& String::operator[](const int i)
{
	return m_str[i];
}

const char& String::operator[](const int i) const
{
	return m_str[i];
}
