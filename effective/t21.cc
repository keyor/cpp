#include <iostream>
using namespace std;

class A{
public:
	A(int i) : num(i) { cout << "ctor" << endl; }
	A(const A &o) { num = o.num; cout << "copy ctor" << endl; }
	const A operator+(const A &r) { return A(num + r.num); }
	~A() { cout << "dtor" <<endl; }
private:
	int num;
};

int main(void)
{
	A a(10);
	A b(20);

	A c = a + b;
	
	return 0;
}
