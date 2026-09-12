#include "Date.h"

//初始化
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

//拷贝构造
Date::Date(const Date& d2)
{
	_year = d2._year;
	_month = d2._month;
	_day = d2._day;
}

//判断是否为闰年
bool Date::IsLeapYear(const int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

//获取当前月份的天数
int Date::GetMonthDay(const int year, const int month)
{
	static int monthDay[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && IsLeapYear(year))
	{
		return 29;
	}
	else
	{
		return monthDay[month];
	}
}

//d1 += 天数
Date& Date::operator+=(const int day)
{
	_day += day;

	int monthDay = GetMonthDay(_year, _month);

	while (_day > monthDay)
	{
		_day -= monthDay;
		++_month;

		if (_month == 13)
		{
			_month = 1;
			++_year;
		}

		monthDay = GetMonthDay(_year, _month);
	}

	return *this;
}

//d1 -= 天数
Date& Date::operator-=(const int day)
{
	_day -= day;

	while (_day < 1)
	{
		--_month;

		if (_month == 0)
		{
			_month = 12;
			--_year;
		}

		int monthDay = GetMonthDay(_year, _month);

		_day += monthDay;
	}

	return *this;
}

//d1 + 天数
Date Date::operator+(const int day) const
{
	Date temp = *this;

	temp += day;

	return temp;
}

//d1 - 天数
Date Date::operator-(const int day) const
{
	Date temp = *this;

	temp -= day;

	return temp;
}

//++d1
Date& Date::operator++()
{
	*this += 1;

	return *this;
}

//d1++
Date Date::operator++(int)
{
	Date temp = *this;

	*this += 1;

	return temp;
}

//--d1
Date& Date::operator--()
{
	*this -= 1;

	return *this;
}

//d1--
Date Date::operator--(int)
{
	Date temp = *this;

	*this -= 1;

	return temp;
}

//d1 < d2
bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
		}
	}

	return false;
}

//d1 > d2
bool Date::operator>(const Date& d) const
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}

	return false;
}

//d1 == d2
bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//d1 != d2
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

//d1 <= d2
bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}

//d1 >= d2
bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

//d1 - d2
int Date::operator-(const Date& d) const
{
	int sign = 1;
	Date max = *this;
	Date min = d;

	if (*this < d)
	{
		sign = -1;
		max = d;
		min = *this;
	}

	int day = 0;

	while (max != min)
	{
		--max;
		++day;
	}

	return sign * day;
}

//打印日期
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << '/' << d._month << '/' << d._day << endl;

	return out;
}