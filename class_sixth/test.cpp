#include <iostream>
#include <cstdlib>
using namespace std;

/*
int i = 10;

class A
{
public:
    A()
    {
      _a = 1;
      _b = 2;
    }
private:
    int _a;
    int _b;
};


class Date
{
public:
    Date(int year, int n)
        :_year(year)
        ,_n(n)
        ,_i(i)
        ,_aa()
    {
      _year = year;
    }
private:
    int _year;

    const int _n;
    int& _i;

    A _aa;
};
*/


/*class A
{
public:
    A(int a)
        :_a1(a)
        ,_a2(_a1)
    {}

    void Print()
    {
        cout << _a1 << " " << _a2 << endl;
    }
private:
    int _a2;
    int _a1;
};*/

/*
class B
{
public:
     B(int b)
        :_b(b)
    {
        cout << "B(int b = 1)" << endl;
        _b = b;
    }

    B(const B& b)
    {
        cout << "B(const B& b)" << endl;
    }
private:
    int _b;
};
*/
/*
class C
{
public:
    C()
    {
        ++_count1;
    }
    C(const C& c)
    {
        ++_count2;
    }

    static int GetCount1()
    {
        return _count1;
    }

    static int GetCount2()
    {
        return _count2;
    }

    void Print()
    {
        GetCount1();
        cout << "" << endl;
    }

private:
    static int _count1;
    static int _count2;
};

C Func(C c)
{
    C copy(c);
    return copy;
}

//定义
int C::_count1 = 0;
int C::_count2 = 0;
*/

class B
{
public:
    B(int b = 0)
        :_b(b)
    {}
    int _b;
};

class A
{
public:
    void Print()
    {
        cout << a << endl;
        cout << b._b << endl;
        cout << p << endl;
    }
private:
    int a = 10;
    B b = 20;
    int* p = (int*)malloc(4);
    static int n;
};
int A::n = 10;

int main()
{
    //Date d1(2022, 5);
    //A aa(1);
    //aa.Print();
    //B b(1);
    //B bb = 2;
    /*C c;
    C c2 = Func(c);
    cout << c.GetCount1()  << endl;
    cout << c2.GetCount1() <<endl;

    cout << c.GetCount1()  << endl;
    cout << c.GetCount2()  << endl;

    cout << C::GetCount1()  << endl;
    cout << C::GetCount2() << endl;*/

    A a;
    a.Print();

    return 0;
}
