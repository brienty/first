#define _CRT_SECURE_NO_WARNINGS 1
#include "template.h"
// a.cpp

// ����ģ�嶨��
template<class T>
T Add(const T& left, const T& right)
{
    return left + right;
}
//ʵ����
template
int Add<int>(const int& left, const int& right);

template
double Add<double>(const double& left, const double& right);


////��ģ�嶨��
//template<class T>
////���ﲻ����0����Ϊֻ�������ſ��ԣ���Ϊ������ȱʡֵ
////����ʼ���б��Ƕ���ʱʹ�õģ����Կ����г�ʼ���б�
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
////��ģ��ʵ����
//template
//class Vector<int>;