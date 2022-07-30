#define _CRT_SECURE_NO_WARNINGS 1

//巧用构造函数
#include <iostream>
class Date
{
public:
    Date()
    {
        int day2;
        std::cin >> _year >> _month >> _day >> day2;
        _day += day2;
        while (_day > returnmonthday(_month, _year))
        {
            _day -= returnmonthday(_month, _year);
            ++_month;
            if (_month > 12)
            {
                ++_year;
                _month = 1;
            }
        }
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

    //打印日期
    void PrintDate()
    {
        if (_month > 9)
            if (_day > 9)
                std::cout << _year << "-" << _month << "-" << _day << std::endl;
            else
                std::cout << _year << "-" << _month << "-0" << _day << std::endl;
        else
            if (_day > 9)
                std::cout << _year << "-0" << _month << "-" << _day << std::endl;
            else
                std::cout << _year << "-0" << _month << "-0" << _day << std::endl;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    int num = 0;
    std::cin >> num;
    int day = 0;
    while (num)
    {
        Date s;
        --num;
        s.PrintDate();
    }
    return 0;
}