#include <iostream>

using namespace std;

//函数重载
//两个函数构成重载,需要参数不同,且在同一作用域
int Add(int a, int b)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}

//缺省参数
//全缺省，全部参数有默认值
void Fun1(int a = 0, int b = 0, int c = 0)
{
	cout << a << ' ' << b << ' ' << c << endl;

	return;
}

//半缺省，部分参数有默认值,需要从右到左依次缺省
void Fun2(int a, int b = 0, int c = 0)
{
	cout << a << ' ' << b << ' ' << c << endl;

	return;
}

//传地址传参与传引用传参
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

//传值返回与传引用返回
//传值返回
int Fun3()
{
	int i = 10;

	//返回的值是i的拷贝
	return i;
}

//传引用返回
int& Fun4()
{
	int i = 10;

	//返回的值是i所在空间的值,结果可能出错
	return i;
}

int main()
{
	//函数重载
	cout << Add(1, 1) << endl;
	cout << Add(1.5, 1.5) << endl;

	//缺省参数
	Fun1();
	Fun2(100);

	//传地址传参与传引用传参
	int x = 0;
	int y = 99;

	Swap1(&x, &y);
	cout << x << ' ' << y << endl;
	Swap2(x, y);
	cout << x << ' ' << y << endl;

	//传值返回与传引用返回
	cout << Fun3() << endl;
	cout << Fun4() << endl;

	return 0;
}