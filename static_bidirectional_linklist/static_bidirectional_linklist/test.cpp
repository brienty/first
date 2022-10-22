#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 100010;

//e[N]�洢��i��Ԫ�ص�ֵ
//r[N]�洢�ұߵ�λ��
//l[N]�洢��ߵ�λ��
//���Կ�ʼ�洢��λ��idx
int e[N], r[N], l[N], idx;

//��ʼ��
void init()
{
	//ֱ��ռ��0��1����2��ʼʹ��
	r[0] = 1, l[1] = 0;
	idx = 2;
}

//k���ұ߲��� 
void add_right(const int k, const int x)
{
	e[idx] = x;//�洢x
	l[idx] = k;//x�����ָ��k
	r[idx] = r[k];//x�ұ�ָ��k���ұ�
	l[r[k]] = idx;//k�ұߵ�Ԫ�ص����ָ��idx
	r[k] = idx;//k���ұ�ָ��idx
}

//k����߲��룬���Կ�����k����ߵ�Ԫ�ؽ����ұߵĲ������
void add_left(const int k, const int x)
{
	int K = l[k];//l[k]��ȡk��ߵ�Ԫ��
	e[idx] = x;//�洢x
	l[idx] = K;//x�����ָ��k
	r[idx] = r[K];//x�ұ�ָ��k���ұ�
	l[r[K]] = idx;//k�ұߵ�Ԫ�ص����ָ��idx
	r[K] = idx;//k���ұ�ָ��idx
}

//ɾ��k
void remove(const int k)
{
	l[r[k]] = l[k];//k�����ָ��k���ұ�
	r[l[k]] = r[k];//k���ұ�ָ��k�����
}
