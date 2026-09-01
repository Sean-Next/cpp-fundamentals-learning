#include <iostream>

using namespace std;

class A1
{
public:
	int add(int x, int y)
	{
		return x + y;
	}
};

class A2
{
public:
	double add(double x, double y)
	{
		return x + y;
	}
};

class B
{};

//this指针
	//类的成员函数可以直接访问成员变量是因为传入了this指针,this指针是隐式的函数参数,它存储对象的地址
	//this存储在栈或寄存器上
	//this指针指向的内容不能改变,this指针的指向可以改变
class C
{
public:
	//add传入了隐式参数this,成员变量前有隐藏的this.
	int add(int _x, int _y)
	{
		return _x + _y;
	}

private:
	int _x;
	int _y;
};

//构造函数
	//构造函数的作用是初始化
class D1
{
public:
	//构造函数名与类相同
	//构造函数无返回值
	//可以不传参的函数为默认构造函数
	D1(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}
private:
	int _a;
	int _b;
	int _c;
};

//构造函数-Init
class D2
{
public:
	//默认构造函数-全缺省函数可以不传参
	D2(int a = 0, int b = 0, int c = 0)
	{
		_a = a;
		_b = b;
		_c = c;
	}
private:
	int _a;
	int _b;
	int _c;
};

class D3
{
public:
	//默认构造函数-无参函数
	D3()
	{
		_a = 0;
		_b = 0;
		_c = 0;
	}
private:
	int _a;
	int _b;
	int _c;
};

class D4
{
	//默认构造函数-不写构造函数,编译器会自动生成一个隐式的构造函数
private:
	int _a;
	int _b;
	class D2;
};

//析构函数
	//析构函数的作用是销毁
class E1
{
public:
	//函数名为~类名
	//无返回值,无参数
	//编译器自动生成的析构函数就是默认析构函数
	~E1()
	{
		;
	}
private:
	int _a;
	int _b;
	int _c;
};

void Fun()
{
	E1 e;

	return;
}

int main()
{

	//类的对象实例化
	A1 a1, a2;
	A2 b1;

	//类域
	//同名函数在同一域下才会重载,不同的类的成员函数属于不同的类域
	cout << a1.add(1, 1) << endl;
	cout << b1.add(1.5, 1.5) << endl;
	//实例化对象不存储函数地址,同一类下不同对象调用的函数都是同一函数
	cout << a1.add(1, 1) << endl;
	cout << a2.add(1, 1) << endl;

	//空类的大小
	//没有成员变量的类的实例化对象的大小为1,证明对象存在
	B e;

	cout << sizeof(e) << endl;

	//对象实例化自动调用构造函数,非默认构造函数需要传参
	D1 c(0, 0, 0);
	//编译器生成的默认构造不一定初始化内置类型
	//初始化自定义类型会调用这个自定义类型的默认构造函数,如果没有默认构造会报错
	D4 d;

	//对象声明周期结束时自动调用析构函数,内置类型不操作,自定义类型会调用这个自定义类型的析构函数
	Fun();

	return 0;
} 