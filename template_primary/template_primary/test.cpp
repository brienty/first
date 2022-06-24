#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(double& left, double right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//
//void Swap(char& left, char right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int t1 = 1, t2 = 2;
//	Swap(t1, t2);
//
//	double d1 = 1.1, d2 = 2.2;
//	Swap(d1, d2);
//
//	char c1 = 1, c2 = 2;
//	Swap(c1, c2);
//
//	return 0;
//}


//template<class T>
//T* func(int n)
//{
//    return new T[n];
//}

// main.cpp
#include "template.h"

int Add(int left, int right)
{
    return left + right;
}

//模板也可以有缺省参数，不过缺省的是类型，和函数参数的意思是一样的
template<typename K = double, typename V = char, typename H = int>
void add()
{
    cout << sizeof(K) << endl;
    cout << sizeof(V) << endl;
    cout << sizeof(H) << endl;
}

int main()
{
    /*int* p1 = func<int>(10);
    double* p2 = func<double>(10);*/

    //Add(1, 2);
    //Add(1.0, 2.0);

    //Vector<int> v1;

    int t1 = 1;
    double d1 = 1.1;
    char c1 = 1;
    //Add<int>(1, 1.1);
    //Add<double>(1, 1.1);
    //Add((double)1, 1.1);
    //Add(1, (int)1.1);//调用非模板函数

    add<>();

    return 0;
}
