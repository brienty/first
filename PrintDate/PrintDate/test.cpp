#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class Date
{
public:
    Date(int year, int day, int month = 1)
        :_year(year)
        , _day(day)
        , _month(month)
    {
        while (_day > getmonthday(_year, _month))
        {
            _day -= getmonthday(_year, _month);
            ++_month;
            if (_month > 12)
            {
                ++_year;
                _month = 1;
            }
        }
    }

    //判断闰年
    bool isleapyear(int year)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return true;
        return false;
    }

    //获取每月天数
    int getmonthday(int year, int month)
    {
        static int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isleapyear(year) && month == 2)
            return 29;
        return arr[month];
    }

    //打印日期
    void PrintDate()
    {
        if (_month > 9)
            if (_day > 9)
                cout << _year << "-" << _month << "-" << _day << endl;
            else
                cout << _year << "-" << _month << "-0" << _day << endl;
        else
            if (_day > 9)
                cout << _year << "-0" << _month << "-" << _day << endl;
            else
                cout << _year << "-0" << _month << "-0" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    int year = 0;
    int day = 0;
    while (scanf("%d %d", &year, &day) != EOF)
    {
        Date d(year, day);
        d.PrintDate();
    }
    return 0;
}