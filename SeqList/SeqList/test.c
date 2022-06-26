#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

/*
	顺序表要求：
	存储的数据从0开始，依次连续存储
*/

//为了方便类型的变换。重定义类型

//测试尾插尾删
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);//传地址
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListDestroy(&s);
}

//测试头插头删
void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);//传地址
	/*
	* 必须先初始化，因为：
	* 顺序表中的空间刚开始是随机值，那就没有办法在这个地址上realloc
	* realloc是对第一个参数表示的内容空间进行调整
	* 在使用顺序表其他操作之后  先把顺序表初始化下   初始化的时候如果么有合适空间了就将a值为NULL
	*/
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -5);
	SeqListPushFront(&s, -6);
	SeqListPushFront(&s, -7);
	SeqListPushFront(&s, -8);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListDestroy(&s);
}

//测试所有功能
void TestSeqList3()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPushFront(&s, -5);
	SeqListPrint(&s);

	SeqListModify(&s, 1, 100);
	SeqListModify(&s, 6, 99);
	SeqListModify(&s, 4, 101);
	SeqListPrint(&s);

	printf("%d\n", SeqListFind(&s, 4));
	SeqListInsert(&s, 4, 78);
	SeqListPrint(&s);
	SeqListErase(&s, 4);
	SeqListPrint(&s);
}


int main()
{
	//如果是这里传过去，那就成二级指针，后面需要二次解引用

	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();

	return 0;
}