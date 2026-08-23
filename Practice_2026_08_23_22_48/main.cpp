#include <iostream>

using namespace std;

//两个Add函数的名字可以相同，因为参数不同
int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

//定义和声明不可同时给缺省
//全缺省，全部参数有默认值
void Fun1(int a = 0, int b = 0, int c = 0)
{
	cout << a << ' ' << b << ' ' << c << endl;

	return;
}

//半缺省，部分参数有默认值
void Fun2(int a, int b = 0, int c = 0)
{
	cout << a << ' ' << b << ' ' << c << endl;

	return;
}

//传地址交换数据
void Swap1(int* px, int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;

	return;
}

//传引用交换数据
void Swap2(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;

	return;
}

//传值返回
int Fun3()
{
	int i = 0;

	return i;
}

//传引用返回
int& Fun4()
{
	int i = 0;

	return i;
}

int main()
{
	int a = 1;
	int b = 2;
	double c = 1.5;
	double d = 2.5;

	//函数重载
	cout << Add(a, b) << ' ' << Add(c, d) << endl;

	//缺省参数
	//不传参数，三个参数默认为0
	Fun1();
	//传一个参数，第一个参数为1其余为0
	Fun2(1);

	//引用
	//x是a的引用
	int& x = a;
	int& y = b;

	//传地址交换
	Swap1(&a, &b);
	//传引用交换
	Swap2(a, b);

	//传值返回
	int i = Fun3();
	//传引用返回可能出错，因为传引用本质是传地址,返回值的值属于函数内部变量已销毁，此时空间内容可能被改写
	int j = Fun4();

	return 0;
}