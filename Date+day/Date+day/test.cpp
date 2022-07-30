#define _CRT_SECURE_NO_WARNINGS 1

//第一种重载+=
#include <iostream>
class Date
{
public:
    friend std::ostream& operator<<(std::ostream& _out, const Date& d);
    friend std::istream& operator>>(std::istream& _in, Date& d);
    Date(int year = 0, int month = 0, int day = 0)
        :_year(year)
        , _month(month)
        , _day(day)
    {}

    ~Date()
    {
        _year = _month = _day = 0;
    }

    //判断闰年
    bool isleap(int year)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            return true;
        }

        return false;
    }

    //获取每月天数
    int returnmonthday(int month, int year)
    {
        static int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isleap(year) && month == 2)
        {
            return 29;
        }

        return arr[month];
    }

    //重载+=运算符
    Date& operator+=(int day)
    {
        while (day)
        {
            if (_day == returnmonthday(_month, _year))
            {
                ++_month;
                _day = 0;
                if (_month > 12)
                {
                    ++_year;
                    _month = 1;
                }
            }
            ++_day;
            --day;
        }

        return *this;
    }
private:
    int _year;
    int _month;
    int _day;
};

//重载<<
std::ostream& operator<<(std::ostream& _out, const Date& d)
{
    if (d._month > 9)
        if (d._day > 9)
            _out << d._year << "-" << d._month << "-" << d._day << std::endl;
        else
            _out << d._year << "-" << d._month << "-0" << d._day << std::endl;
    else
        if (d._day > 9)
            _out << d._year << "-0" << d._month << "-" << d._day << std::endl;
        else
            _out << d._year << "-0" << d._month << "-0" << d._day << std::endl;
    return _out;
}

//重载>>
std::istream& operator>>(std::istream& _in, Date& d)
{
    _in >> d._year >> d._month >> d._day;
    return _in;
}

int main()
{
    int num = 0;
    std::cin >> num;
    int day = 0;
    while (num)
    {
        Date s;
        std::cin >> s >> day;
        s += day;
        std::cout << s;
        --num;
    }
    return 0;
}