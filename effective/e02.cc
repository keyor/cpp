#include <iostream>
using namespace std;

class A{
public:
	void print(void) { cout << num << endl; }
private:
	static const int num = 5;
};

int main(void)
{
	A a;

	a.print();
	
	return 0;
}
