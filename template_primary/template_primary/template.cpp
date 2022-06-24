#define _CRT_SECURE_NO_WARNINGS 1
#include "template.h"
// a.cpp

// 函数模板定义
template<class T>
T Add(const T& left, const T& right)
{
    return left + right;
}
//实例化
template
int Add<int>(const int& left, const int& right);

template
double Add<double>(const double& left, const double& right);


////类模板定义
//template<class T>
////这里不等于0是因为只有声明才可以，因为给的是缺省值
////而初始化列表是定义时使用的，所以可以有初始化列表
//Vector<T>::Vector(int capacity)
//	:_capacity(capacity)
//	, _size(0)
//	, _a(new T[capacity])
//{}
//
//template<class T>
//void Vector<T>::PushBack(const T& x)
//{
//
//}
//
////类模板实例化
//template
//class Vector<int>;