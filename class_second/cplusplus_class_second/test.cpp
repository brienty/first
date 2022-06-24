#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

////���캯��
//class Date
//{
//public:
//    // 1.�޲ι��캯��
//    Date()
//    {
//        _year = 2022;
//        _month = 5;
//        _day = 17;
//    }
//
//    // 2.���ι��캯��
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
//    Date d1; // �����޲ι��캯��
//    Date d2(2015, 1, 1); // ���ô��εĹ��캯��
//    Date d3(); // ����d3����
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
//            cout << "~SeqList��" << this << endl;
//            free(_pData); // �ͷŶ��ϵĿռ�
//            _pData = NULL; // ��ָ����Ϊ��
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
//    // ��������(��������)
//    int _year = 0;//ȱʡֵ
//    int _month;
//    int _day;
//    // �Զ�������
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
//    //����
//    Stack(int capacity = 10)
//    {
//        _a = (int*)malloc(sizeof(int) * capacity);
//        assert(_a);
//
//        _top = 0;
//        _capacity = capacity;
//    }
//    //��������
//    Stack(const Stack& st)
//    {
//        _a = st._a;
//        _top = st._top;
//        _capacity = st._capacity;
//    }
//    //����
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
//    //��ʼ��ջ
//    Stack st1 ;
//    //��������ջ
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
//    // ����d2���õ�Ĭ�Ͽ���������ɿ�����d2��d1��ֵҲ��һ���ġ�
//    Date d2(d1);
//    d1.Print();
//    d2.Print();
//    return 0;
//}

// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ�����
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