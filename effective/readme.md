# Effective C++

## 让自己习惯C++

### 条款1：视C++为一个语言联邦
	把C++当作4部分次语言组成，每个次语言组成有其规则
	C、Object C++、Template C++、STL
	C++高效编程守则视状况而变化，取决于你用C++哪部分。

### 条款2：尽量用const、enum、inline替换 #define
	对于单纯常量,最好以const对象或enums替换#defines
	对于形似函数的宏,最好改用inline函数替换#defines

### 条款3：尽可能使用const
	编写程序时应该使用"概念上的常量性",尽管编译器强制实施二进位常量性
	当const和no-const成员函数有实质等价实现时，令non-const版本调用cosnt版本可避免代码重复

### 条款4：确定对象被使用前已被初始化
	为内置型对象进行手工初始化，因为c++不保证初始化它们
	构造函数最好使用成员初始值列表，其列表中成员出现的顺序和它们在类中声明的次序一致
	为免除"跨编译单元之初始化次序"问题，用局部静态对象替换全局对象,然后在函数中返回它的引用。
	//如果在一个模块中使用另一个模块的某个类对象，则可以把该类对象定义为局部 static ClassName obj,并且提供函数返回
	//这样,防止了当前模块使用另一个模块的全局对象，但该对象未初始化的问题

### 条款5：了解C++默默编写并调用的函数
	创建一个空类，编译器会编译默认构造函数、拷贝构造函数、拷贝赋值运算符、析构函数
	如果你定义一个带参的构造函数,则编译器不会再自动产生一个默认构造函数，因为你需要用参数来初始化对象

### 条款6: 若不想使用编译器自动生成的函数，就该明确拒绝
	如果真的不需要拷贝构造函数或拷贝赋值运算符，可以把拷贝构造函数和拷贝赋值运算符声明为private;
		或者定义一个父类，父类中把拷贝构造函数和拷贝赋值运算符声明为private
	
### 条款7：为多态基类声明virtual析构函数
	如果需要定义一个接口，一个途径就是把虚基类的析构函数声明为纯虚函数，并实现它
		因为在使用中会调用基类的析构函数

### 条款8：别让异常逃离析构函数
	在析构函数内捕获异常，如果出错则记录并调用sta::abort()结束,或者吞下这个错误虽然这很不妥。
	如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class应该提供一个普通函数
		而非在析构函数中执行该操作。

### 条款9：绝不在构造或析构函数中调用virtual函数
	在构造或析构期间不要调用virtual函数,因为这类调用从不下降至派生类

### 条款10：令operator= 返回一个reference to *this
	
### 条款11:	在 operator= 中处理自我赋值

### 条款12：复制每一个对象时勿忘其每一个成分
	任何时候只要“为派生类撰写copying函数”时,必须小心复制其base class成分，
		一般来说,那些成分往往是private,所以只能在派生类的copying函数中调用
		相应的base class函数
	copying函数应该确保复制"对象内的所有成员变量"及"所有的base class成分"
	不要尝试以某个copying函数实现令一个copying函数，应该将共同机能放在第三个函数中，并由两个copying函数共同调用
	示例:
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


## 资源管理
### 条款13: 

### 条款9
	





































# More Effective C++ 

## 基础议题
### 条款1: 仔细区分pointers 和 references
	当你知道你需要指向某个东西，而且绝不会改变指向其他东西;或是当你实现一个操作符而其语法需求无法由pointers达成，
	你就应该选择references。其他任何时候，请采用 pointers。

### 条款2: 最好使用c++转型运算符

### 条款3: 绝对不要以多态方式处理数组
	错误用法就是定义一个接口，其接受父类的数组，但是实际调用时却使用子类数组去调用

### 条款4：非必要不提供默认构造函数
	类如果自身数据成员必须被定义才能初始化，则不应该使用默认构造函数;尽管建立一个定义时必须给数据成员明确之值的类数组有限制
	但也不应该使用一些无意义的值来放在默认构造函数中，因为在后续的使用需要不断测试。
	所以定义此类类数据成员创建时必须有初始值的类对象时，可以使用placement new
	void *radMem = operator new [] (10 * sizeof(EquipmentPiece));
	EquipmentPiece *p = static_cast<radMem*>(radMem);
	for(int i = 0; i < 10; i++)
		new (&p[i]) EquipmentPiece(ID number);
	//销毁
	for(int i = 9; i >= 0; i--)
		p[i].~EquipmentPiece();
	operator delete[](radMem);

## 操作符
### 条款5：对定制的"类型转换函数"保持警觉
	隐式类型操作符一个成员函数，形式 operator 转换的类型名称(), 其返回值类型就是转换的类型
	隐式转换类型操作符的缺点就是，它的出现可能导致错误的函数被调用
	对于单自变量构造函数，尽可能使用explicit声明，让其取消隐式类型转换
	因为有时自身出错，编译器检测时弄出一些不希望的效果

### 条款6：区别increment/decrement操作符的前置和后置形式
	UPint& operator++(); //前置
	const UPint operator++(int) //后置,int参数是为填补漏洞，而且在函数中不使用
	后置可以在前置的基础上实现，一般来说应该推荐使用前置++/--

### 条款7：千万不要重载&&、 || 和 ,操作符

### 条款8：了解各种不同意义的new和delete
	string *ps = new string("这是new operator,相当于sizeof")
	new operator 调用 operator new 函数执行内存分配动作，
	我们可以重载这个函数即 operator new, operator new 只负责分配内存
	void *operator new(size_t size)
	调用的时候直接如下调用
		void *rawMemory = operator new(sizeof(string));
	
	如果已经分配好的原始内存，需要在上面构建对象，则使用 placement new
	placement new 是一个特殊的 operator new, 
	它只负责在分配好的内存上构建对象,然后返回指向该对象的指针
	原型如下
		void *operator new(size_t, void *p) throw() { return p; }
	
	placement new 的用法如下
		return new (buffer) obj(init)

## 异常
### 条款9：利用destruct避免资源泄漏
	把资源封装在对象内，利用智能指针分配资源，如果后续出现异常，则可以自动销毁相应的资源。
	意1：
		如果创建一个类，该类分配了资源，但是类成员函数在操作中有可能出现异常，则应该把类资源交给对象管理，
			即智能指针，这样只需要在分配时考虑资源分配异常情况就可以了

### 条款10：在constructs内阻止资源泄漏
	设计constructs时，必须考虑构造期报异常的情况，否则半成品析构函数不能释放它。
	c++只会析构已经构造完的对象，但是如果是在创建一个对象时，如果某个数据成员new报出异常，则over
	利用异常抓到也毫无卵用，在一个类的constructs中所有的new必须成功，否则用智能指针也不行
	一般是利用智能指针，然后在初始化时利用?:表达式对成员赋值
	theImage( imageFileName != "" ? new Image(imageFileName) : 0), ... {}  //列表初始化及ctor花括号
	// 
	class A{
	public:
		A(const char *s) { buffer = new char[static_cast<int>(strlen(s)) + 1]; strcpy(buffer, s); cout << "a ctor " << endl;}
		~A() { delete [] buffer; cout << "a dtor" << endl; }
	private:
		char *buffer;
	};

	class B{
		public:
			B(int i, const char *s) : len(i), t(s != NULL ? make_shared<A>(s) : nullptr), e(s != NULL ? make_shared<A>(s) : nullptr)  { cout << "b ctor" << endl; }
			~B() { cout << "b dtor" << endl; }
		private:
			int len;
			shared_ptr<A> t;
			shared_ptr<A> e;
	};


### 条款11：禁止异常流出destruct之外
	

### 条款12：了解"抛出一个异常"与"传递一个参数"或"调用一个虚函数"之间的差异
	

### 条款13：以by reference方式捕捉exceptions

### 条款14：明智运用exception specifications

### 条款15：了解异常处理的成本

## 效率
### 条款16：谨记80-20法则
	一个程序80%的时间花费在20%的代码上。
	检查一个程序的性能瓶颈，也就是找出那关键的20%,那么利用软件分析程序的时候
	输入的数据必须是可重制的

### 条款17：考虑使用lazy evaluation(缓式评估)
	以某种方式编写你的classes,使它们延缓运行，直到那些运算结果刻不容缓地被迫切需要为止。
	如果其运算结果一直不被需要，运算也就一直不执行。

### 条款18：分期摊还预期的计算成本(超急评估)
	令程序做超前进度地做“要求以外”的工作。
	如果你预期程序常常会用到某个计算，你可以降低每次计算的成本，方法是设计一份数据结构以便能够
		极有效率地处理需求。

### 条款19: 了解临时对象的来源
	看到任何reference-to-const参数，就极有可能有一个临时对象被产生出来绑定至该参数上;
		看到任何函数返回一个对象，就会产生一个临时对象
	
### 条款20：协助完成“返回值优化”
	如果函数真的必须要返回一个对象，则直接在return 里创建，函数名声明为inline.
	运算符重载中，必须有一个是用户自定义类型

### 条款21：
