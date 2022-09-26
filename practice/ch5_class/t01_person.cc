#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Person{
public:
	Person(const char* _name, const char* _addr) : name(_name), addr(_addr) {}
	const string& getName(void) const { return name; }
	const string& getAddr(void) const { return addr; }
	friend istream& read(istream &is, Person &p);
	void print() const { cout << name << " , " << addr << endl; }
private:
	string name;
	string addr;
};

istream& read(istream &is, shared_ptr<Person> &p)
{
	try{
		is >> p.name >> p.addr;
	}catch(exception e)
		
	return is;
}


int main(void)
{
	Person p("panjiasheng", "GZ");

	p.print();

	shared_ptr<Person> sp = NULL;

	read(cin, sp);

	return 0;
}
