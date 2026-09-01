#include <iostream>
#include "test.h"

//全部展开
using namespace std;

//部分展开
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int year = 2026;

	//将要打印的不同类型内容,以字符串的形式插入到流中,endl作用与'\n'相似,都进行换行操作
	cout << "hello world ！" << endl << "你的出生年份是";
	cin >> year;

	//"test.h"中的函数Fun()被命名空间封装,需要::指定寻找域
	test::Fun();

	return 0;
}