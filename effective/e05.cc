#include <iostream>
using namespace std;

class A{
public:
	A(int n) : num(n) {}
private:
	int num;
};

class B{

};

int main(void)
{
	A a(2);
	A b(a);
	A c(1);
	c = a;

	return 0;
}
