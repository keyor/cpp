#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s = "hello";

	cout << s[3] << endl;

	s[3] = 'x';

	cout << s << endl;

	return 0;
}
