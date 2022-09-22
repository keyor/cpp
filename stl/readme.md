## 1.vector
	vector是动态分配的数组，如果需要就两倍扩容
	vector里有三个迭代器,相当于3个指针，start指向vector起点,finish指向终点,end_of_storage指向容器的终点，一个空的vector利用sizeof()返回的就是3个指针的大小
	begin()-> return start
	end()-> return finish
	size()-> return begin() - end()
	empty()-> return begin() == end()
	capacity()-> return end_of_storage - start
	clear() 清除vector的元素，但内存未必释放
	shrink_to_fit() 请求容器减小其容量以适应其大小;一般来说先 clear()容器，然后再调用shrink_to_fit来缩小容器的capacity
	resize() 改变容器大小，如果之前是空容器，则会分配相应的内存空间，而不像reserve()使用容器预留空间这种
	erase(iterator postion) / erase(iterator begin, iterator end) 使用erase()会删除元素，但是对容器容量无影响。


## 2.set/multiset
	底层实现红黑树,容器具有元素自动排序。无法使用set的迭代器对其中的元素进行修改
	从set里拿到的迭代器，其类型是const类型的迭代器，也就是不能修改set里面的内容
	可以直接使用数组来初始化向量
	添加元素 insert(val) / insert(iterator it_postion, val): 其实用迭代器没啥用，因为set会自动排序
	删除元素 erase(val) / erase(iterator it) / erase(iterator first, iterator last)
	查找元素 find(val) 返回的iterator 如果不等于 end()，则表示找到这个元素
	lower_bound(val) / upper_bound(val) 返回iterator，通过和end()对比，分别是迭代器指向不小于/不大于val的位置

## 3.map/multmap
	底层使用红黑树，容器具有元素自动排序。map的key必须唯一
	insert(pair<t1,t2>(v1,v2)) 
	find(key) 成功返回iterator指向的位置，失败end()
	lower_bound(key) 低于key之前的
	upper_bound(key) 高于key的迭代器
	count(key) map有的话返回1, multimap返回有多少元素使用这个key
