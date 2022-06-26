#define _CRT_SECURE_NO_WARNINGS 1


/*
	双向带头循环链表，需要注意的是为了接口的一致性，我们这里所有采用一级指针
	需要的地方则使用返回值的形式代替
*/



#include "List.h"

void Test1()
{
	LTNode* plist = ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushFront(plist, 0);
	ListPushFront(plist, -1);
	ListPushFront(plist, -2);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
}


void Test2()
{
	LTNode* plist = ListInit();

	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushFront(plist, 0);
	ListPushFront(plist, -1);
	ListPushFront(plist, -2);
	ListPrint(plist);

	LTNode* pos = ListFind(plist, 0);

	ListInsert(pos, 100);
	ListPrint(plist);

	ListErase(pos);//别像个傻子一样把哨兵位放进去，不然就野指针了
	ListPrint(plist);

	ListDestroy(plist);

	//必须要这步，因为函数里的是形参，形参不影响实参
	plist = NULL;

}

int main()
{
	//Test1();
	Test2();
	return 0;
}