#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
using std:: cout;
using std:: cin;
using std:: endl;


//前置声明，因为编译器向上找不到Date
class Date;

class Time
{
    friend void Func(const Date& d, const Time& t);
public:
    Time(int hour = 0, int mintue = 0, int second = 0)
        : _hour(hour)
        , _mintue(mintue)
        , _second(second)
    {}
private:
    int _hour;
    int _mintue;
    int _second;
};

class Date
{
    friend void Func(const Date& d, const Time& t);
public:
    Date(int year = 1, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}
private:
    int _year;
    int _month;
    int _day;
};

void Func(const Date& d, const Time& t)
{
    cout << t._hour << endl;
    cout << d._year << endl;
}


class A
{
private:
    static int k;
    int h;
public:
    class B
    {
    public:
        void func(const A& a)
        {
            cout << k << endl;
            cout << a.h << endl;
        }
    };
};

int A::k = 1;

int main()
{
    Date d(2022, 5, 25);
    Time t;
    Func(d, t);

    //创建对象
    A::B b;
    
    //访问b中的函数
    b.func(A());
    return 0;
}
