#include <iostream>
#include "test.h"

using namespace std;

//宏函数
#define ADD(a, b) ((a) + (b))

//内联函数定义
inline int add(int a, int b)
{
	return a + b;
}

void Fun1(int a)
{
	cout << "我是int" << endl;

	return;
}

void Fun1(int* a)
{
	cout << "我是int*" << endl;

	return;
}


int main()
{
	//引用的权限可以缩小，不可以放大
	//b的权限比a大，不能做a的引用，c与a的权限相同，可以做引用
	const int a = 5;
	//int& b = a;
	const int& c = a;
	//e的权限小于d可以做引用
	int d = 5;
	const int& e = d;

	//类型转换
	int f;
	double g = 5.0;
	//类型转换本质是用临时空间复制并处理g的数据，经过处理存入f变量
	f = g;
	//这里h引用的不是g，而是引用复制g的临时空间，临时空间不可以被修改
	//int& h = g;
	//想要引用需要加const，防止临时空间被修改
	const int& i = g;

	//引用与指针区别
	int j = 10;
	//引用必须初始化，指针不用
	int& k = j;
	int* pj;
	pj = &j;
	//引用不能改变指向，指针可以
	//int& k = d;
	pj = &d;
	//引用直接就能访问指向对象，指针需要解引用
	cout << k << endl;
	cout << *pj << endl;

	//nullptr与NULL
	//NULL平时使用都是当作地址,但是因为#define NULL 0,会优先把它当作整型
	Fun1(NULL);
	//nullptr没有这样的问题，可以代替NULL
	Fun1(nullptr);

	//内联代替宏
	//宏函数太复杂，容易出错，不能调试
	cout << ADD(1, 1) << endl;
	//内联函数同样可以展开而不去开函数栈帧，但是内联不是强制的，如果函数太复杂编译器也不会展开
	cout << add(1, 1) << endl;
	//内联函数声明与定义不能分离,链接器会找不到函数定义
	//cout << add(1.5, 1.5) << endl;

	//封装
	class A
	{
	//让外面的内容可以访问public下面的成员	
	public:
		//类里面可以定义函数,可以无条件的访问其他成员
		double Fun2(int q)
		{
			return q * _a * _b;
		}
	//让外面的内容不可以访问private下面的成员
	private:
		int _a;
		double _b;
	};
	//创建对象
	A m;
	//可以访问m的成员
	m.Fun2(5);
	//不可访问
	//m._a;

	return 0;
}