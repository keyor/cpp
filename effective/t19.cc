#include <iostream>
using namespace std;

class A{
public:
	A(int i) : num(i) { cout << "a ctor" << endl; }
	~A() { cout << "a dtor" << endl; }
	friend void printA(const A&);
private:
	int num;
};

void printA(const A& o)
{
	cout << o.num << endl;
}

int main(void)
{
	A n(1);
	
	printA(n);

	return 0;
}
