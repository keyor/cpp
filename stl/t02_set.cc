#include <set>
#include <iostream>
using namespace std;

int main(void)
{
	set<int> mset;
	cout << "sizeof(mset): " << sizeof(mset) << endl;
	
	mset = {5,4,3};

	cout << "mset.size(): " << mset.size() << endl;
	cout << "mset.max_size(): " << mset.max_size() << endl;
	cout << "mset.empty(): " << mset.empty() << endl;
	cout << "mset.count(4): " << mset.count(4) << endl;

	// 添加元素
	mset.insert(2);
	set<int>::iterator it = mset.begin();
	mset.insert(it, 9);
	
	cout << "mset.size()：" << mset.size() << endl;
	for(it = mset.begin(); it != mset.end(); it++)
		cout << *it << " ";
	cout << endl;

	mset.erase(mset.begin());
	mset.erase(9);
	for(it = mset.begin(); it != mset.end(); it++)
		cout << *it << " ";
	cout << endl;
	
	cout << "删除元素后， mset.size(): " << mset.size() << endl;
	
	it = mset.find(4);
	if(it != mset.end())
		cout << "mset.find(4), *it = " << *it << endl;

	mset.insert(9);
	mset.insert(10);
	mset.insert(20);
	mset.insert(30);

	it = mset.lower_bound(10);
	if(it != mset.end())
	{
		cout << "遍历不低于10的元素, mset.lower_bound(10)" << endl;
		for(; it != mset.end(); it++)
			cout << *it << " ";
		cout << endl;
	}

	auto uit = mset.upper_bound(10);
	if(uit != mset.end())
	{
		cout << "遍历不大于10的元素， mset.upper_bound(10)" << endl;
		for(it = mset.begin(); it != uit; it++)
			cout << *it << " ";
		cout << endl;
	}

	return 0;
}
