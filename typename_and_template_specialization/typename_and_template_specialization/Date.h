#pragma once
#include <iostream>
#include <assert.h>
using std::cout;
using std::cin;
using std::endl;

class Date
{
	// 友元函数
	friend std::ostream& operator<<(std::ostream& out, const Date& d);
	friend std::istream& operator>>(std::istream& out, Date& d);
public:
	bool isLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	int GetMonthDay(int year, int month);

	// 默认生成的析构函数，内置类型成员不做处理，自定义类型成员会去调用它的析构函数
	Date(int year = 1, int month = 1, int day = 1);

	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	//Date& operator=(const Date& d)
	//{
	//	if (this != &d)
	//	{
	//		_year = d._year;
	//		_month = d._month;
	//		_day = d._day;
	//	}

	//	return *this;
	//}

	// 建议成员函数中不修改成员变量的成员函数，都可以加上const
	// 普通对象和const对象都可以调用
	// void Print(const Date* const this)
	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	Date operator+(int day)  const;
	Date& operator+=(int day);

	Date operator-(int day)  const;
	Date& operator-=(int day);

	// ++d1
	Date& operator++()      // 前置
	{
		*this += 1;
		return *this;
	}

	// d1++
	Date operator++(int) // 后置
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	Date& operator--()     // 前置
	{
		*this -= 1;
		return *this;
	}

	Date operator--(int) // 后置
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	// d1 - d2
	int operator-(const Date& d) const;

	bool operator==(const Date& d)  const;
	bool operator<(const Date& d)  const;

	// inline不支持声明和定义分别放到.h 和.cpp
	// 所以成员函数中要成为inline最好直接在类里面定义
	// 类里面定义默认就是inline
	bool operator>(const Date& d)  const
	{
		return !(*this <= d);
	}

	bool operator>=(const Date& d)  const
	{
		return !(*this < d);
	}

	bool operator!=(const Date& d)  const
	{
		return  !(*this == d);
	}

	// d1 <= d2
	bool operator<=(const Date& d)  const
	{
		return *this < d || *this == d;
	}

	//Date* operator&()
	//{
	//	//return this;
	//	return nullptr;
	//}

	//const Date* operator&() const
	//{
	//	//return this;
	//	return nullptr;
	//}

	//void operator<<(std::ostream& out)
	//{
	//	out << _year << "-" << _month << "-" << _day << endl;
	//}

	//void operator>>(std::istream& in)
	//{

	//}
private:
	int _year;
	int _month;
	int _day;
};