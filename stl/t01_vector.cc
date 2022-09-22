#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v;
	
	cout << "空vector的大小，仅包含3个指针，sizeof(v): " << sizeof(v) << endl;

	vector<int> vec{1,2,3,4,5};
	
	// finish - start
	cout << "vec.size(): " << vec.size() << endl;
	
	// end_of_storage - start
	cout << "vec.capacity(): " << vec.capacity() << endl;
	
	// 加入元素,两倍扩容了
	vec.push_back(6);
	cout << "vec.capacity(): " << vec.capacity() << endl;
	
	vec.clear();
	cout << "vec.clear():\n 销毁vec容器中的所有元素，但内存并未释放; vec.size(): " << vec.size() << ", vec.capacity(): " << vec.capacity() << endl;
	
	vec.shrink_to_fit();
	cout << "vec.shrink_to_fit():\n 销毁vector分配的内存空间, vec.capacity(): " << vec.capacity() << endl;
	
	// 出错，并没有内存空间
	// vec.front() = 1;
	vec.resize(1);
	vec.front() = 1;

	vec.push_back(2);

	vec.push_back(3);
	
	cout << "vec.capacity() : " << vec.capacity() << endl;

	vector<int>::iterator it = vec.begin();
	for(; it != vec.end(); it++)
		cout << *it << endl;
	
	cout << "vec.max_size() : " << vec.max_size() << endl;
	
	cout << "vec.size() : " << vec.size() << endl;
	
	vec.erase(vec.begin() + vec.size() - 1);
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	
	vec.erase(vec.begin(), vec.end());

	cout << "vec.size(): " << vec.size() << ", vec.capacity(): " << vec.capacity() << endl;
	

	return 0;
}
