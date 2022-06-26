#define _CRT_SECURE_NO_WARNINGS 1


/*
	˫���ͷѭ��������Ҫע�����Ϊ�˽ӿڵ�һ���ԣ������������в���һ��ָ��
	��Ҫ�ĵط���ʹ�÷���ֵ����ʽ����
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

	ListErase(pos);//�����ɵ��һ�����ڱ�λ�Ž�ȥ����Ȼ��Ұָ����
	ListPrint(plist);

	ListDestroy(plist);

	//����Ҫ�ⲽ����Ϊ����������βΣ��ββ�Ӱ��ʵ��
	plist = NULL;

}

int main()
{
	//Test1();
	Test2();
	return 0;
}