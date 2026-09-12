#include "Date.h"

//初始化构造测试
void test01()
{
	Date d1(2026, 9, 12);
	
	cout << d1;

	return;
}

//拷贝构造测试
void test02()
{
	Date d1(2026, 9, 12);
	Date d2(d1);

	cout << d1 << d2;

	return;
}

//判断是否为闰年测试
void test03()
{
	cout << Date::IsLeapYear(1900) << ' ';
	cout << Date::IsLeapYear(2000) << endl;

	return;
}

//获取当前月份的天数测试
void test04()
{
	cout << Date::GetMonthDay(1900, 2) << ' ';
	cout << Date::GetMonthDay(2000, 2) << endl;

	return;
}

//d += day运算符重载测试
void test05()
{
	Date d1(2026, 9, 12);
	d1 += 100;

	cout << d1;

	return;
}

//d -= day运算符重载测试
void test06()
{
	Date d1(2026, 12, 21);
	d1 -= 100;

	cout << d1;

	return;
}

//d + day运算符重载测试
void test07()
{
	Date d1(2026, 9, 12);

	cout << (d1 + 100);

	return;
}

//d - day运算符重载测试
void test08()
{
	Date d1(2026, 12, 21);

	cout << (d1 - 100);

	return;
}

//++d运算符重载测试
void test09()
{
	Date d1(2026, 9, 12);

	cout << ++d1;

	return;
}

//d++运算符重载测试
void test10()
{
	Date d1(2026, 9, 12);

	cout << d1++;
	cout << d1++;

	return;
}


//--d运算符重载测试
void test11()
{
	Date d1(2026, 9, 12);

	cout << --d1;

	return;
}

//d--运算符重载测试
void test12()
{
	Date d1(2026, 9, 12);

	cout << d1--;
	cout << d1--;

	return;
}

//d1 < d2运算符重载
void test13()
{
	Date d1(2026, 9, 12);
	Date d2(2026, 12, 21);

	cout << (d1 < d2) << ' ';

	return;
}

//d1 > d2运算符重载
void test14()
{
	Date d1(2026, 9, 12);
	Date d2(2026, 12, 21);

	cout << (d1 > d2) << ' ';

	return;
}

//d1 == d2运算符重载
void test15()
{
	Date d1(2026, 9, 12);
	Date d2(2026, 9, 12);

	cout << (d1 == d2) << ' ';

	return;
}

//d1 != d2运算符重载
void test16()
{
	Date d1(2026, 9, 12);
	Date d2(2026, 9, 12);

	cout << (d1 != d2) << ' ';

	return;
}

//d1 <= d2运算符重载
void test17()
{
	Date d1(2026, 9, 12);
	Date d2(2026, 12, 21);

	cout << (d1 <= d2) << ' ';

	return;
}

//d1 >= d2运算符重载
void test18()
{
	Date d1(2026, 9, 12);
	Date d2(2026, 12, 21);

	cout << (d1 >= d2) << ' ' << endl;

	return;
}

//d1 - d2运算符重载
void test19()
{
	Date d1(2026, 9, 12);
	Date d2(2026, 12, 21);

	cout << (d2 - d1) << endl;

	return;
}

int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
	test10();
	test11();
	test12();
	test13();
	test14();
	test15();
	test16();
	test17();
	test18();
	test19();

	return 0;
}