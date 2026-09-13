#include <iostream>

using namespace std;

class A
{
public:
	//&运算符重载
	A* operator&()
	{
		return this;
	}

	//const修饰this指针
	const A* operator&() const
	{
		return this;
	}
};

class B
{
public:
	//静态成员变量
	static int a;

	//静态成员函数
	static void Fun1()
	{
		//静态成员函数可以访问其它静态成员
		cout << a;

		return;
	}

	//非静态成员可以声明缺省值
	int b = 0;

	void Fun2()
	{
		//非静态成员可以访问静态成员
		//反之不行因为静态成员函数无this指针
		cout << a << b;
		Fun1();

		return;
	}
};

class C2
{
public:
	int _a;
	int _b;
};

int B::a = 0;

class C1
{
public:
	//初始化构造
	C1(int a)
	{
		_a = a;
		_b = a;
		_c = a;

		cout << "初始化构造1" << endl;
	}

	C1(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;

		cout << "初始化构造2" << endl;
	}

	//拷贝构造
	C1(const C1& x)
	{
		_a = x._a;
		_b = x._b;
		_c = x._c;

		cout << "拷贝构造" << endl;
	}

	//C2转换C1构造
	C1(const C2& y)
	{
		_a = y._a;
		_b = y._b;
		_c = y._a * y._b;
	}

	int _a;
	int _b;
	int _c;
};

//初始化列表
class D
{
public:
	D()
		:a(100)
		//就算初始化列表没显示初始化,也会跟据缺省值隐示初始化
		//,b(1,2,3)
		,c(b)
	{
		;
	}

	//const变量,无默认构造的自定义类型变量,引用,都要用初始化列表或声明缺省值
	const int a;
	C1 b = {1,2,3};
	C1& c;
	//既未显示初始化也未声明缺省值的内置类型,编译器会初始化为0或随机值
	int d;
	//既未显示初始化也未声明缺省值的自定义类型,编译器会调用它的默认构造,没有默认构造会报错
	C2 e;
};




int main()
{
	//取对象地址
	A a;
	cout << &a << endl;

	B b;
	B* ptr = &b;

	//静态成员函数三种调用方式
	B::Fun1();
	b.Fun1();
	ptr->Fun1();
	cout << endl;

	//类型转换
	//不打印拷贝构造是因为编译器优化掉临时变量
	C1 c1 = 9;

	//出现引用则不会优化掉,因为引用的是临时变量
	const C1& c2 = 8;

	//可以传多个参数
	C1 c3 = { 1,2,3 };

	//自定义类型可以转化为其它自定义类型
	//前提是有相应的构造函数
	C2 c;
	C1 c4 = c;

	return 0;
}