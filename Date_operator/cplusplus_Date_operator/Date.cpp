#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

bool Date::Isleapyear(const int& year)const 
{
	//四年一润，百年不润，四百年润
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int Date::GetMonthDay(const int& year, const int& month)const
{
	//对应下标访问月份天数，使用static就不要一直创建数组，可以提高效率，防止多线程安全则加const
    const static int MonthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30 };

	//二月份闰年处理
	if (month == 2 && Isleapyear(year))
	{
		return 29;
	}
	else
	{
		return MonthDayArray[month];
	}
}




//=重载
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;;
	_day = d._day;

	//传引用，减少拷贝
	return *this;
}

//==重载
bool Date::operator==(const Date& d)const
{
	return ((_year == d._year) && (_month == d._month) && (_day == d._day));
}

//<重载
bool Date::operator<(const Date& d)const
{
	if ((_year < d._year) ||
		(_year == d._year && _month < d._month) ||
		(_year == d._year && _month == d._month && _day < d._day))
	{
		return true;
	}
	else
	{
		return false;
	}
}



// 日期+=天数
Date& Date::operator+=(int day)
{
	//处理天数带入负数时的情况
	if (day < 0)
	{
		*this -= -day;//注意是-day，不然会-=和+=反复运行
		return *this;
	}

	//将需要加的天数加上
	_day += day;
	//处理溢出问题
	while (_day > GetMonthDay(_year, _month))
	{
		//更新天
		_day -= GetMonthDay(_year, _month);
		//月+1
		++_month;
		//年+1
		if (_month > 12)
		{
			_month = 1;
			++_year;
		}
	}
	//传引用比传值效率高
	return *this;
}

// 日期-=天数
Date& Date::operator-=(int day)
{
	//处理带入负数的情况
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	//这里与+=同理
	_day -= day;

	while (_day < 0)
	{
		--_month;
		if (_month < 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

// 日期-日期 返回天数
int Date::operator-(const Date& d)const
{
	//找到谁大谁小
	Date max = *this;
	Date min = d;
	//需要返回负或正的天数
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	//计算max和min中间的天数
	int num = 0;
	while (max != min)
	{
		++min;
		++num;
	}

	return flag * num;
}

//cout重载
std::ostream& operator<<(std::ostream& _out, const Date& d)
{
    /*这里获取每月的天数遇到了一个问题，去取对象里的获取每月天数函数时，由于我们的对象是只读的，但是一开始我们GetMonthDay设置的是可读可写的，这里对象去调用获取每月天数时，就出现了权限的放大，由于GetMonthDay还调用了IsLeapyear函数，所以IsLeapyear函数也要是只读的，不能可读可写*/
    if(d._year > 0 && d._month > 0 && d._month < 13 && d._day > 0 && d._day <= d.GetMonthDay(d._year, d._month))
    {
         _out << d._year << "-" << d._month << "-" << d._day << endl;
    }
    else
    {
        _out << "illegal input!"<< endl;
    }
    return _out;
}

//cin重载
std::istream& operator>>(std::istream& _in, Date& d)
{
    _in >> d._year >> d._month >> d._day;
    return _in;
}







