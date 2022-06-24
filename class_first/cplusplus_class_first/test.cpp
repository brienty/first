#define _CRT_SECURE_NO_WARNINGS 1

#include "func.h"

////用struct创建类，在变量前加_是习惯，以示区别
//struct Student
//{
//    //成员函数
//    void SetStudentInfo(const char* name, const char* gender, int age)
//    {
//        strcpy(_name, name);
//        strcpy(_gender, gender);
//        _age = age;
//    }
//
//    //成员函数
//    void PrintStudentInfo()
//    {
//        cout << _name << " " << _gender << " " << _age << endl;
//    }
//
//    //成员变量，这里的成员变量可以在任意位置，因为在寻找成员变量时是在这个类型里寻找
//    char _name[20];
//    char _gender[3];
//    int _age;
//};

//用struct创建类，在变量前加_是习惯，以示区别
class Student
{
public:
    //成员函数
    void SetStudentInfo(const char* name, const char* gender, int age)
    {
        strcpy(_name, name);
        strcpy(_gender, gender);
        _age = age;
    }

    //成员函数
    void PrintStudentInfo()
    {
        cout << _name << " " << _gender << " " << _age << endl;
    }

private:
    //成员变量，这里的成员变量可以在任意位置，因为在寻找成员变量时是在这个类型里寻找
    char _name[20];
    char _gender[3];
    int _age;
};

//类定义了一个作用域，两个push函数的作用域不同
class stack
{
public:
    void push(int x)
    {}
};
class queue
{
public:
    void push(int x)
    {}
};

// 类中既有成员变量，又有成员函数
class A1 {
public:
    void f1() {}
private:
    int _a;
};
// 类中仅有成员函数
class A2 {
public:
    void f2() {}
};
// 类中什么都没有---空类
class A3 {
};


class Date
{
public:
    void Display()
    {
        cout << this << endl;
        cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
    }

    void SetDate(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
private:
    int _year; // 年
    int _month; // 月
    int _day; // 日
};

class C
{
public:
    void PrintC()
    {
        cout << this->_a << endl;
    }

    void Show()
    {
        cout << "Show()" << endl;
    }
public:
    int _a;
};

int main()
{
    //Student s;
    //s.SetStudentInfo("Peter", "男", 18);

    ///*Stack st;
    //st.push(10);*/

    //A1 a1;
    //A2 a2;
    //A3 a3;
    //cout << sizeof(a1) << endl;
    //cout << sizeof(a2) << endl;
    //cout << sizeof(a3) << endl;

    Date d1, d2;

    cout << &d1 << endl;
    cout << &d2 << endl;

    d1.SetDate(2022, 5, 17);
    d2.SetDate(2022, 5, 18);
    d1.Display();
    d2.Display();

    C* p = nullptr;

    //p->PrintC();

    p->Show();

    return 0;
}