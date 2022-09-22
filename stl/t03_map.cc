#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void)
{
	map<string,int> sta;

	sta.insert(pair<string,int>("赵日天",99));
	sta.insert(pair<string,int>("王大锤",100));

	sta.insert(pair<string,int>("龙傲天",80));
	sta.insert(pair<string,int>("叶良辰",70));

	cout << "sta.size(): " << sta.size() << endl;
	for(auto it = sta.begin(); it != sta.end(); it++)
		cout << it->first << " : " << it->second << " " << endl ;
	
	auto it = sta.find("赵日天");
	if(it != sta.end())
		cout << "赵日天存在，成绩为: " << it->second << endl;
	
	cout << "查找低于赵日天的第一个元素" << endl;

	auto itl = sta.lower_bound("赵日天");
	for(it = sta.begin(); it != itl; it++)
		cout << it->first << " : " << it->second << endl;
	
	cout << "查找高于赵日天的第一个元素" << endl;
	auto itu = sta.upper_bound("赵日天");
	for(; itu != sta.end(); itu++)
		cout << itu->first << " : " << itu->second << endl;
	
	cout << "移除叶良辰" << endl;
	sta.erase("叶良辰");

	cout << "sta.size() : " << sta.size() << endl;

	return 0;
}
