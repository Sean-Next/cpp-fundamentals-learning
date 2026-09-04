#include <iostream>

using namespace std;

//内联函数与宏函数
//宏函数
#define ADD(a, b) ((a) + (b))

//内联函数
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
	//权限的放大与缩小
	//权限不能放大,身为a的引用,b的权限不能比a大
	const int a = 10;
	const int& b = a;

	//权限可以缩小,身为c的引用,d的权限可以比c小
	int c = 10;
	const int& d = c;

	//在进行类型转换时,临时变量拷贝e,f其实是临时变量的引用,临时变量不可改写
	double e = 1.5;
	const int& f = e;


	//引用与指针区别
	int g = 10;
	int h = 10;
	
	//引用必须初始化,指针不用初始化
	int& i = g;
	int* pg;

	//引用不能改变指向,指针可以改变指向
	pg = &g;
	pg = &h;

	//引用直接就能访问指向对象,指针需要解引用
	int j;
	j = i;
	j = *pg;
	

	//nullptr与NULL
	//NULL默认被当作整型
	Fun1(NULL);

	//nullptr默认被当作地址
	Fun1(nullptr);

	//宏函数与内联函数
	//宏函数太复杂,容易出错,不能调试
	cout << ADD(1, 1) << endl;

	//内联函数可以不创建函数栈帧,可以像宏一样直接展开,内联不是强制的,如果函数复杂编译器不会展开
	//内联函数声明与定义不能分离,链接器会找不到函数定义
	cout << add(1, 1) << endl;

	//类
	class A
	{
	//让类外面可以访问类里面public下面的成员	
	public:
		//类里面可以定义函数,成员函数可以直接访问其他成员变量
		double Fun2(int k)
		{
			return k * _a * _b;
		}

	//让外面不可以访问类里面private下面的成员
	private:
		int _a;
		double _b;
	};

	//实例化对象
	A l;

	//可以访问对象l的成员函数,不可以访问成员变量
	l.Fun2(5);

	return 0;
}