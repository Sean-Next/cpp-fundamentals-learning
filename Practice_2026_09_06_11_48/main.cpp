#include <iostream>
#include <stdlib.h>

using namespace std;

//拷贝构造
class A
{
public:
	A(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}

	//拷贝构造函数不能传值传参,否则会死递归
	A(const A& x)
	{
		_a = x._a;
		_b = x._b;
		_c = x._c;
	}
	int _a;
	int _b;
	int _c;
};

//浅拷贝与深拷贝
class B1
{
public:
	B1(int a, int b, int c)
	{
		_a = a;
		_b = b;
		_c = c;
	}

	//浅拷贝
	B1(const B1& x)
	{
		//只进行值的拷贝
		_a = x._a;
		_b = x._b;
		_c = x._c;
	}
	int _a;
	int _b;
	int _c;
};

class B2
{
public:
	B2(int size = 4)
	{
		_arr = (int*)malloc(size);
		_size = size;
	}

	//深拷贝
	B2(const B2& x)
	{
		//不止进行值的拷贝,还需对指向的空间进行处理
		_arr = (int*)malloc(x._size);

		memcpy(_arr, x._arr, x._size);

		_size = x._size;
	}
	int* _arr;
	int _size;
};

//默认拷贝构造
class C
{
public:
	//内置类型直接拷贝
	int _a;
	int _b;
	//自定义类型会调用它对应的拷贝构造
	B2 _c;
};

//运算符重载
class D
{
public:
	int _a;
	int _b;
	int _c;

	D(int a = 0, int b = 0, int c = 0)
	{
		_a = a;
		_b = b;
		_c = c;
	}

	//以函数的形式重新定义运算符+的含义
	D& operator+(D const x)
	{
		D d;
		d._a = _a + x._a;
		d._b = _b + x._b;
		d._c = _c + x._c;

		return d;
	}

	//重新定义运算符前置++的含义
	D& operator++()
	{
		++_a;
		++_b;
		++_c;

		return *this;
	}

	//重新定义运算符后置++的含义
	//前置++与后置++的运算符重载相同,所以需要传类型int区分
	D operator++(int)
	{
		D ret = *this;
		++_a;
		++_b;
		++_c;

		return ret;
	}
};

class E
{
public:
	void Fun()
	{
		cout << "调用函数成功" << endl;
	}
};

//默认赋值运算符重载
class F1
{
public:
	F1(int a = 0, int b = 0, int c = 0)
	{
		_a = a;
		_b = b;
		_c = c;
	}

	int _a;
	int _b;
	int _c;
};








int main()
{
	//拷贝构造初始化
	A a1(0, 0, 0);
	A a2(a1);
	A a3 = a1;

	//浅拷贝
	B1 b1(0, 0, 0);
	B1 b2 = b1;

	//深拷贝
	B2 b3(4);
	*(int*)b3._arr = 0;
	B2 b4 = b3;

	//默认拷贝构造
	C c1;
	*(int*)c1._c._arr = 0;
	C c2 = c1;

	//运算符重载
	D d1(1, 1, 1);
	D d2(1, 1, 1);
	cout << (d1 + d2)._a << (d1 + d2)._b << (d1 + d2)._c << endl;
	
	++d1;
	cout << d1._a << d1._b << d1._c << endl;

	d1++;
	cout << d1._a << d1._b << d1._c << endl;

	//.*操作符
	E e;
	void(E::*p)() = &E::Fun;
	(e.*p)();

	//默认赋值运算符重载
	F1 f1(1, 2, 3);
	F1 f2;
	//会对内置类型进行浅拷贝,自定义类型会调用相应的赋值运算符重载
	f2 = f1;

	cout << f2._a << f2._b << f2._c << endl;

	return 0;
}

