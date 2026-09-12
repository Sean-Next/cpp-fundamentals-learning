#pragma once

#include <iostream>

using namespace std;

class Date
{
	//友元函数
	friend ostream& operator<<(ostream& out, const Date& d);

public:

	//初始化
	Date(int year = 1, int month = 1, int day = 1);

	//拷贝构造
	Date(const Date& d2);


	//判断是否为闰年
	static bool IsLeapYear(const int year);

	//获取当前月份的天数
	static int GetMonthDay(const int year, const int month);


	//d += day运算符重载
	Date& operator+=(const int day);

	//d -= day运算符重载
	Date& operator-=(const int day);

	//d + day运算符重载
	Date operator+(const int day) const;

	//d - day运算符重载
	Date operator-(const int day) const;

	//++d运算符重载
	Date& operator++();

	//d++运算符重载
	Date operator++(int);

	//--d运算符重载
	Date& operator--();

	//d--运算符重载
	Date operator--(int);

	//d1 < d2运算符重载
	bool operator<(const Date& d) const;

	//d1 > d2运算符重载
	bool operator>(const Date& d) const;

	//d1 == d2运算符重载
	bool operator==(const Date& d) const;

	//d1 != d2运算符重载
	bool operator!=(const Date& d) const;

	//d1 <= d2运算符重载
	bool operator<=(const Date& d) const;

	//d1 >= d2运算符重载
	bool operator>=(const Date& d) const;

	//d1 - d2运算符重载
	int operator-(const Date& d) const;

private:
	//年
	int _year;
	//月
	int _month;
	//日
	int _day;
};

//打印日期
ostream& operator<<(ostream& out, const Date& d);
