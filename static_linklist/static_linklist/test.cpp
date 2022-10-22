#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*
	由于动态链表在new时很消耗时间，在数据量非常大的时候会超时
	实现一个静态链表，在操作合法的情况下，完成以下函数：
	1、链表的初始化
	2、链表的头插
	3、链表的第k个位置的后面插入
	4、删除第k个位置后面的元素
*/

//开辟的数组大小
const int N = 100010;

//head头结点下标
//e[N]表示结点i的值
//ne[N]结点i的next指针是多少
//idx存储当前已经用到了哪个点
int head, e[N], ne[N], idx;

//初始化head和idx
void init()
{
	head = -1;
	idx = 0;
}

//将x插入到头结点
void add_to_head(const int x)
{
	e[idx] = x;//存储x的值
	ne[idx] = head;//让x的next指向head的next的元素
	head = idx;//head指向x
	++idx;//++idx
}

//将x插入到下标是k的结点的后面
void add(const int k, const int x)
{
	e[idx] = x;//存储x的值
	ne[idx] = ne[k];//让x的next指向k的next的元素
	ne[k] = idx;//让k的next指向x
	++idx;//++idx
}

//将下标是k的结点的后面的结点删除
void remove(const int k)
{
	ne[k] = ne[ne[k]];//让k指向next元素的next的元素
}

int main()
{
	init();//初始化链表
	
	//测试输入数据：10 H 9 I 1 1 D 1 D 0 H 6 I 3 6 I 4 5 I 4 5 I 3 4 D 6
	int m = 0;
	cin >> m;
	while (m--)
	{
		
		char op = 0;
		cin >> op;
		//头插
		if (op == 'H')
		{
			int x = 0;
			cin >> x;
			add_to_head(x);
		}
		//插入
		else if (op == 'I')
		{
			int k = 0, x = 0;
			cin >> k >> x;
			add(k - 1, x);//下标0开始，应该是k-1
		}
		//删除结点
		else
		{
			int k = 0;
			cin >> k;
			//这里需要特判，因为删除头结点时，head应该是指向head的next，即头结点的下一个结点，不应该进去删除
			if (!k) 
				head = ne[head];
			else 
				remove(k - 1);//下标0开始应该是k-1
		}	
	}
	//输出，从头结点开始输出数据 
	for (int i = head; i != -1; i = ne[i])
	{
		cout << e[i] << " ";
	}
	cout << endl;
}