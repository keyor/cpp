#include <iostream>
#include <memory>
#include <cstring>
using namespace std;


class String{
public:
	explicit String(const char* s) : len(strlen(s)+1), sp(new char[strlen(s)+1], [](char* ptr){ delete [] ptr; cout << "删他妈的坑多多" << endl;} ) { 
		auto p = sp.get();
		for(int i = 0; i < strlen(s); i++)
			*(p+i) = s[i];
	}
	
	String(const String& rhs);

	String& operator=(const String &rhs);

private:

	void clear(char * ptr) { delete [] ptr; cout << "删他妈的坑多多" << endl; }
	
	void copyStr(const String& rhs);

private:
	int len = 0;
	shared_ptr<char> sp = nullptr;
};

void String::copyStr(const String& rhs)
{
	auto ps = rhs.sp.get();
	auto pd = sp.get();

	strcpy(pd, ps);
}

String::String(const String& rhs) : len(rhs.len), sp(new char[len], [](char* ptr){ delete [] ptr; cout << "删他妈的坑多多" << endl;} )
{
	copyStr(rhs);				
}

/*
String& String::operator=(const String &rhs)
{
	if(this != &rhs)
	{
		
	}
}
*/


int main(void)
{
	String a("hello");
	
	String b(a);	

	return 0;
}
