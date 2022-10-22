#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 100010;

//e[N]存储第i个元素的值
//r[N]存储右边的位置
//l[N]存储左边的位置
//可以开始存储的位置idx
int e[N], r[N], l[N], idx;

//初始化
void init()
{
	//直接占用0和1，从2开始使用
	r[0] = 1, l[1] = 0;
	idx = 2;
}

//k的右边插入 
void add_right(const int k, const int x)
{
	e[idx] = x;//存储x
	l[idx] = k;//x的左边指向k
	r[idx] = r[k];//x右边指向k的右边
	l[r[k]] = idx;//k右边的元素的左边指向idx
	r[k] = idx;//k的右边指向idx
}

//k的左边插入，可以看成是k的左边的元素进行右边的插入操作
void add_left(const int k, const int x)
{
	int K = l[k];//l[k]获取k左边的元素
	e[idx] = x;//存储x
	l[idx] = K;//x的左边指向k
	r[idx] = r[K];//x右边指向k的右边
	l[r[K]] = idx;//k右边的元素的左边指向idx
	r[K] = idx;//k的右边指向idx
}

//删除k
void remove(const int k)
{
	l[r[k]] = l[k];//k的左边指向k的右边
	r[l[k]] = r[k];//k的右边指向k的左边
}
