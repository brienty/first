#include <iostream>
using namespace std;


//const练习
class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    
    void Print()const
    {
        cout << _year << "-" << _month << "-" << _day <<endl;
    }
    
    Date* operator&()
    {
        return this;
    }

    //这里的两个const都不能少，一个是修饰*this，函数重载
    //一个是返回类是const Date*，与参数类匹配
    const Date* operator&()const
    {
        return this;
    }



private:
    int _year;
    int _month;
    int _day;
};

//const Date* d
void Test(const Date& d)
{
    d.Print();
    cout << &d << endl;
}

int main()
{

    Date d1(2022, 5, 22);
    Test(d1);
    cout << &d1 << endl;
    return 0;
}
