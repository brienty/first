#pragma once

//函数模板声明
template<class T>
T Add(const T& left, const T& right);

//类模板声明
template<class T>
class Vector 
{
public:
	Vector(int capacity = 10);
	void PushBack(const T& x);
private:
	int _capacity;
	int _size;
	T* _a;
};
//类模板定义
template<class T>
//这里不等于0是因为只有声明才可以，因为给的是缺省值
//而初始化列表是定义时使用的，所以可以有初始化列表
Vector<T>::Vector(int capacity)
	:_capacity(capacity)
	, _size(0)
	, _a(new T[capacity])
{}

template<class T>
void Vector<T>::PushBack(const T& x)
{

}