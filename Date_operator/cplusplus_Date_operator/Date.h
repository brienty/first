#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Date
{
    friend std::ostream& operator<<(std::ostream& _out, const Date& d);
    friend std::istream& operator>>(std::istream& _in, Date& d);
public:
	//创建默认构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		//非法输入处理
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "输入有误，请重新输入！" << endl;
		}
	}
	//析构函数可以不用创建，拷贝构造函数也可以不用创建
	//为了方便查看特性，这里会完成拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//取每月天数
	int GetMonthDay(const int& year, const int& month)const;

	//返回是否是闰年
	bool Isleapyear(const int& year)const;



	//==重载
	bool operator==(const Date& d)const;

	//=重载
	Date& operator=(const Date& d);

	//<重载
	bool operator<(const Date& d)const;

	// 日期+=天数
	Date& operator+=(int day);

	// 日期-=天数
	Date& operator-=(int day);

	// 日期-日期 返回天数
	int operator-(const Date& d)const;



	//以下复用了函数的函数采用内联的函数
	//!=重载
	bool operator!=(const Date& d)const
	{
		//复用等于
		return (!(*this == d));
	}

	//<=重载
	bool operator<=(const Date& d)const
	{
		//复用<和==
		return ((*this) < d || (*this) == d);
	}

	//>重载
	bool operator>(const Date& d)const
	{
		//复用小于等于
		return (!(*this <= d));
	}

	//>=重载
	bool operator>=(const Date& d)const
	{
		//复用小于
		return (!(*this < d));
	}




	// 日期+天数
	Date operator+(int day)const
	{
		//这里使用+复用+=而不是+=复用+的原因是+要进行两次拷贝，而+=不用拷贝
		//同时调用两个函数时，只用拷贝两次而不是四次，效率更高

		//本身不能改
		Date ret = *this;

		ret += day;//复用+=

		return ret;//ret会销毁，只能传值
	}

	// 日期-天数
	Date operator-(int day)const
	{
		Date ret = *this;

		ret -= day;//复用-=

		return ret;
	}
	


	// 前置++
	Date& operator++()
	{
		*this += 1;//复用+=

		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date ret = *this;

		*this += 1;//复用+=

		return ret;
	}

	// 前置--
	Date& operator--()
	{
		*this -= 1;//复用-=

		return *this;
	}

	// 后置--
	Date operator--(int)
	{
		Date ret = *this;

		*this -= 1;//复用-=

		return ret;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	
private:
	int _year;
	int _month;
	int _day;
};
