#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

//const����
class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    //����Ĳ���Ӧ����const Date* const this
    void Print()const
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

//�������ֱ�ӱ���
void Func(const Date& d)
{
    d.Print();//d1.Print(&d);->d1.Print(const Date* d);
}

//����d.Print()����
void Test()
{
    Date d1(2022, 5, 18);
    d1.Print();//d1.Print(&d1);->d1.Print(Date* d1);
    Func(d1);
}

int main()
{
    Test();
    return 0;
}