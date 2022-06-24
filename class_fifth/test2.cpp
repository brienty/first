#include <iostream>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& out, Date& d);
public:
    Date(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
private:
    int _year;
    int _month;
    int _day;
};

//<<重载
ostream& operator<<(ostream& out, const Date& d)
{
    out << d._year << "-" << d._month << "-" << d._day;

    return out;
}

istream& operator>>(istream& out, Date& d)
{
    out >> d._year >> d._month >> d._day;
    return out;
}

int main()
{
    Date d1;
    cin >> d1;
    cout << d1 <<endl;
    return 0;
}
