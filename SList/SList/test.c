#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

/*
	单链表，在链表中，链表为空是合法的，因为链表为空代表它是个空链表
	与顺序表不同，顺序表为空是不存在，不存在即为非法的
	所以这里看不到assert函数
*/
/*
	注：值得一提的是
	SListPushBack(NULL, date)
	在链表里，这种情况才是不存在，因为传的第一个结点是NULL
	说明不存在这个链表，即非法
	而当NULL处传的是一个有效的指针并指针被赋值为空，说明存在该链表，并且该链表为空链表
	注意传的是空指针还是一个有效的指针，以此来辨别是否存在
*/

//测试尾插
void Test1()
{
	/*
		这里注意一个问题，为什么使用的是指针而不是结构体
		这里直接创建的是结点，而在顺序表中是一次性先创建整个顺序表，不够再扩容
		所以使用指针指向结点，既然是指针指向结点，那么初始化自然是按常理先赋值NULL 
	*/
	SListNode* slist = NULL;//空链表
	for (int i = 0; i < 4; i++)
	{
		//结构体传参传地址
		SListPushBack(&slist, i);
	}
	PrintSList(slist);
}

int main()
{
	Test1();
	return 0;
}