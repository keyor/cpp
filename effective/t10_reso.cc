#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class A{
public:
	A(const char *s) { buffer = new char[static_cast<int>(strlen(s)) + 1]; strcpy(buffer, s); cout << "a ctor " << endl;}
	~A() { delete [] buffer; cout << "a dtor" << endl; }
private:
	char *buffer;
};

class B{
	public:
		B(int i, const char *s) : len(i), t(s != NULL ? make_shared<A>(s) : nullptr), e(s != NULL ? make_shared<A>(s) : nullptr)  { cout << "b ctor" << endl; }
		~B() { cout << "b dtor" << endl; }
	private:
		int len;
		shared_ptr<A> t;
		shared_ptr<A> e;
};

int main(void)
{
	B obj(5, "hello");	

	return 0;
}
