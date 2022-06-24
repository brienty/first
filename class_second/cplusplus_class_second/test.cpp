#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

////构造函数
//class Date
//{
//public:
//    // 1.无参构造函数
//    Date()
//    {
//        _year = 2022;
//        _month = 5;
//        _day = 17;
//    }
//
//    // 2.带参构造函数
//    Date(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//void TestDate()
//{
//    Date d1; // 调用无参构造函数
//    Date d2(2015, 1, 1); // 调用带参的构造函数
//    Date d3(); // 声明d3函数
//}
//
//int main()
//{
//    TestDate();
//    return 0;
//}

//class Time
//{
//public:
//    Time()
//    {
//        cout << "Time()" << endl;
//        _hour = 0;
//        _minute = 0;
//        _second = 0;
//    }
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};

//typedef int DataType;
//class SeqList
//{
//public:
//    SeqList(int capacity = 10)
//    {
//        _pData = (DataType*)malloc(capacity * sizeof(DataType));
//        assert(_pData);
//
//        _size = 0;
//        _capacity = capacity;
//    }
//
//    ~SeqList()
//    {
//        if (_pData)
//        {
//            cout << "~SeqList：" << this << endl;
//            free(_pData); // 释放堆上的空间
//            _pData = NULL; // 将指针置为空
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//
//private:
//    int* _pData;
//    size_t _size;
//    size_t _capacity;
//};
//
//class Date
//{
//private:
//    // 基本类型(内置类型)
//    int _year = 0;//缺省值
//    int _month;
//    int _day;
//    // 自定义类型
//    //Time _t;
//    SeqList s1;
//    SeqList s2;
//};
//
//int main()
//{
//    Date d;
//    return 0;
//}

//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    Date(const Date& d)
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//void Func(Date d)
//{
//    
//}
//
//class Stack {
//public:
//    //构造
//    Stack(int capacity = 10)
//    {
//        _a = (int*)malloc(sizeof(int) * capacity);
//        assert(_a);
//
//        _top = 0;
//        _capacity = capacity;
//    }
//    //拷贝构造
//    Stack(const Stack& st)
//    {
//        _a = st._a;
//        _top = st._top;
//        _capacity = st._capacity;
//    }
//    //析构
//    ~Stack()
//    {
//        free(_a);
//        _a = nullptr;
//        _top = _capacity;
//    }
//private:
//    int* _a;
//    int _top;
//    int _capacity;
//};
//
//
//int main()
//{
//    /*Date d1;
//    Date d2(d1);*/
//    //初始化栈
//    Stack st1 ;
//    //拷贝构造栈
//    Stack st2(st1);
//    return 0;
//}

//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    void Print()
//    {
//        cout << _year << _month << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    Date d1(2022, 5, 18);
//    // 这里d2调用的默认拷贝构造完成拷贝，d2和d1的值也是一样的。
//    Date d2(d1);
//    d1.Print();
//    d2.Print();
//    return 0;
//}

// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。
class String
{
public:
    String(const char* str = "jack")
    {
        _str = (char*)malloc(strlen(str) + 1);
        assert(_str);
        strcpy(_str, str);
    }
    ~String()
    {
        cout << "~String()" << endl;
        free(_str);
    }
private:
    char* _str;
};
int main()
{
    String s1("hello");
    String s2(s1);
}