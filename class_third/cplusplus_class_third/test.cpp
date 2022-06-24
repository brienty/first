#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


//日期类
class Date
{
public:

	//构造函数，需要自己写，不能使用默认的
	Date(int year = 1, int month = 1, int day = 1)
	{
		//禁止非法输入
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= Getmonthday(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "输入非法！" << endl;
		}
	}

	//拷贝函数，可以不用自己写，可以使用默认的，这里自己写是为了方便查看Date d1 = d2 和 Date d1(d2) 是否一样只是调用了拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//析构函数可以使用默认的，这里没有资源需要清理
	~Date()
	{
		_year = 1;
		_month = 1;
		_day = 1;
	}

	bool Isleapyear(const int& year)
	{
		//四年一润，百年不润，四百年一润
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Getmonthday(const int& year, const int& month)
	{
		//注意润平年，使用static可以提高程序的运行效率
		static int date[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,30 };
		//二月份需要额外处理
		if (month == 2 && Isleapyear(year))
		{
			return 29;
		}
		else
		{
			return date[month];
		}
	}

	// 打印日期
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	//判等运算符重载
	bool operator==(const Date& d2)
	{
		return ((this->_year == d2._year) && (this->_month == d2._month) && (this->_day == d2._day));
	}

	//不等运算符重载
	bool operator!=(const Date& d2)
	{
		//传址效率更高
		//return !(*this == d2);效率低下，需要调用重载的==函数，又需要拷贝
		return !(this == &d2);
	}

	//赋值操作符重载，其实赋值操作符本来就是有返回值的，因为需要支持连续赋值
	Date& operator=(const Date& d2)
	{
		//处理赋值给自己
		if(this != &d2)
		{
			_year = d2._year;
			_month = d2._month;
			_day = d2._day;
		}
		
		//this被销毁，d1没有，返回引用没有问题
		return *this;
	}

	//小于操作符重载
	bool operator<(const Date& d2)
	{
		if ((_year < d2._year) || 
			(_year == d2._year && _month < d2._month) ||
			(_year == d2._year && _month == d2._month && _day < d2._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//大于操作符重载
	bool operator>(const Date& d2)
	{
		if ((_year > d2._year) ||
			(_year == d2._year && _month > d2._month) ||
			(_year == d2._year && _month == d2._month && _day > d2._day))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//小于等于操作符重载
	bool operator<=(const Date& d2)
	{
		return !(*this > d2);
	}

	//大于等于操作符重载
	bool operator>=(const Date& d2)
	{
		return !(*this < d2);
	}

	// 日期+=天数
	Date& operator+=(int day)
	{
		_day = _day + day;

	}

	// 日期+天数
	Date operator+(int day);

	// 日期-天数
	Date operator-(int day);

	// 日期-=天数
	Date& operator-=(int day);

	// 前置++
	Date& operator++();

	// 后置++
	Date operator++(int);

	// 后置--
	Date operator--(int);

	// 前置--
	Date& operator--();

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2022, 3, 19);
	Date d2(2022, 2, 29);
	d1.Print();
	d2.Print();

	Date d3;
	//这里的赋值操作符并没有起作用，这里使用的拷贝构造函数，调试
	Date d4 = d3;
	//以下代码拷贝才使用了重载赋值操作符
	Date d5(2022, 1, 1);
	Date d6;
	d6 = d5;
	d6.Print();
	d5.Print();
	if (d1 == d2)
	{
		cout << "==" << endl;
	}
	if (d1 != d2)
	{
		cout << "!=" << endl;
	}
	if (d1 <= d2)
	{
		cout << "<=" << endl;
	}
	if (d1 >= d2)
	{
		cout << ">=" << endl;
	}
	if (d1 < d2)
	{
		cout << "<" << endl;
	}
	if (d1 > d2)
	{
		cout << ">" << endl;
	}
	return 0;
}