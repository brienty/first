#pragma once

//����ģ������
template<class T>
T Add(const T& left, const T& right);

//��ģ������
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
//��ģ�嶨��
template<class T>
//���ﲻ����0����Ϊֻ�������ſ��ԣ���Ϊ������ȱʡֵ
//����ʼ���б��Ƕ���ʱʹ�õģ����Կ����г�ʼ���б�
Vector<T>::Vector(int capacity)
	:_capacity(capacity)
	, _size(0)
	, _a(new T[capacity])
{}

template<class T>
void Vector<T>::PushBack(const T& x)
{

}