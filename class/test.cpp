#include <iostream>

using namespace std;


class Date
{
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

    //拷贝构造函数
    Date(const Date& d)
    {
        _year = d.year;
        _month = d._month;
        _day = d._day;
    }

    void Print()
    {

    }
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	return 0;
}
