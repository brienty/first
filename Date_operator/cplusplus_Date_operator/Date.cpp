#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

bool Date::Isleapyear(const int& year)const 
{
	//����һ�󣬰��겻���İ�����
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int Date::GetMonthDay(const int& year, const int& month)const
{
	//��Ӧ�±�����·�������ʹ��static�Ͳ�Ҫһֱ�������飬�������Ч�ʣ���ֹ���̰߳�ȫ���const
    const static int MonthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 30 };

	//���·����괦��
	if (month == 2 && Isleapyear(year))
	{
		return 29;
	}
	else
	{
		return MonthDayArray[month];
	}
}




//=����
Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;;
	_day = d._day;

	//�����ã����ٿ���
	return *this;
}

//==����
bool Date::operator==(const Date& d)const
{
	return ((_year == d._year) && (_month == d._month) && (_day == d._day));
}

//<����
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



// ����+=����
Date& Date::operator+=(int day)
{
	//�����������븺��ʱ�����
	if (day < 0)
	{
		*this -= -day;//ע����-day����Ȼ��-=��+=��������
		return *this;
	}

	//����Ҫ�ӵ���������
	_day += day;
	//�����������
	while (_day > GetMonthDay(_year, _month))
	{
		//������
		_day -= GetMonthDay(_year, _month);
		//��+1
		++_month;
		//��+1
		if (_month > 12)
		{
			_month = 1;
			++_year;
		}
	}
	//�����ñȴ�ֵЧ�ʸ�
	return *this;
}

// ����-=����
Date& Date::operator-=(int day)
{
	//������븺�������
	if (day < 0)
	{
		*this += -day;
		return *this;
	}
	//������+=ͬ��
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

// ����-���� ��������
int Date::operator-(const Date& d)const
{
	//�ҵ�˭��˭С
	Date max = *this;
	Date min = d;
	//��Ҫ���ظ�����������
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	//����max��min�м������
	int num = 0;
	while (max != min)
	{
		++min;
		++num;
	}

	return flag * num;
}

//cout����
std::ostream& operator<<(std::ostream& _out, const Date& d)
{
    /*�����ȡÿ�µ�����������һ�����⣬ȥȡ������Ļ�ȡÿ����������ʱ���������ǵĶ�����ֻ���ģ�����һ��ʼ����GetMonthDay���õ��ǿɶ���д�ģ��������ȥ���û�ȡÿ������ʱ���ͳ�����Ȩ�޵ķŴ�����GetMonthDay��������IsLeapyear����������IsLeapyear����ҲҪ��ֻ���ģ����ܿɶ���д*/
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

//cin����
std::istream& operator>>(std::istream& _in, Date& d)
{
    _in >> d._year >> d._month >> d._day;
    return _in;
}







