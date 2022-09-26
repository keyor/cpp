#include <iostream>
using namespace std;

class base{
public:
	base(int i) : num(i) { cout << " b ctor" << endl; }
	
	base(const base& rhs) { num = rhs.num; cout << "b copy ctor " << endl; }

	base& operator=(const base& rhs) { 
		if(this != &rhs) 
			num = rhs.num; 
		cout << "b operator= " << endl; 
		return *this; 
	}

private:
	int num;
};

class derived : public base {
public:
	derived(int n, int a) : base(n), age(a) {}

	derived(const derived& rhs) : base(rhs), age(rhs.age) { cout << "d copy ctor" << endl; }

	derived& operator=(const derived& rhs) {
		if(this != &rhs)
		{	
			base::operator=(rhs);
			age = rhs.age;
		}
		cout << "d operator=" << endl;
		return *this;
	}

private:
	int age;
};

int main(void)
{
	derived b(10,20);

	derived a(b);

	return 0;
}
