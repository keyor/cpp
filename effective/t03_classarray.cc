#include <iostream>
using namespace std;

class A{
	public:
		A(int i): num{i} {}

	private:
		int num = 0;
};

class B : public A{
	public:
		B(int i, int j): A(i), size(j) {}
	private:
		int size = 0;
};

void printA( const A arr[], int len)
{
	for(int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(void)
{
	A[2] = new A[2]{1,2};
	
	printA(A, 2);


	return 0;
}
