#define _CRT_SECURE_NO_WARNINGS 1

#include "func.h"

////��struct�����࣬�ڱ���ǰ��_��ϰ�ߣ���ʾ����
//struct Student
//{
//    //��Ա����
//    void SetStudentInfo(const char* name, const char* gender, int age)
//    {
//        strcpy(_name, name);
//        strcpy(_gender, gender);
//        _age = age;
//    }
//
//    //��Ա����
//    void PrintStudentInfo()
//    {
//        cout << _name << " " << _gender << " " << _age << endl;
//    }
//
//    //��Ա����������ĳ�Ա��������������λ�ã���Ϊ��Ѱ�ҳ�Ա����ʱ�������������Ѱ��
//    char _name[20];
//    char _gender[3];
//    int _age;
//};

//��struct�����࣬�ڱ���ǰ��_��ϰ�ߣ���ʾ����
class Student
{
public:
    //��Ա����
    void SetStudentInfo(const char* name, const char* gender, int age)
    {
        strcpy(_name, name);
        strcpy(_gender, gender);
        _age = age;
    }

    //��Ա����
    void PrintStudentInfo()
    {
        cout << _name << " " << _gender << " " << _age << endl;
    }

private:
    //��Ա����������ĳ�Ա��������������λ�ã���Ϊ��Ѱ�ҳ�Ա����ʱ�������������Ѱ��
    char _name[20];
    char _gender[3];
    int _age;
};

//�ඨ����һ������������push������������ͬ
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

// ���м��г�Ա���������г�Ա����
class A1 {
public:
    void f1() {}
private:
    int _a;
};
// ���н��г�Ա����
class A2 {
public:
    void f2() {}
};
// ����ʲô��û��---����
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
    int _year; // ��
    int _month; // ��
    int _day; // ��
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
    //s.SetStudentInfo("Peter", "��", 18);

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