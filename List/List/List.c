#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//创建结点
LTNode* BuyListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	//失败即终止程序
	if (newnode == NULL)
	{
		printf("error\n");
		exit(-1);
	}

	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->val = x;

	return newnode;
}

//初始化，创建链表的哨兵位的头结点，必须返回，不然没改变实际的哨兵位
LTNode* ListInit()
{
	LTNode* phead = BuyListNode(0);//给予任意值，哨兵位的头结点不存数据

	//一开始next和prev都指向自己
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

//尾插，不需要返回，插在哨兵位结点后，传值
void ListPushBack(LTNode* phead, LTDateType x)
{
	//传的哨兵位不能为空
	assert(phead);

	////创建结点
	//LTNode* newnode = BuyListNode(x);

	////使用tail遍历
	//LTNode* tail = phead->prev;

	////最后一个结点交接
	//tail->next = newnode;
	//newnode->prev = tail;

	////让最后一个结点与哨兵位结点成循环
	//phead->prev = newnode;
	//newnode->next = phead;


	//采用Insert函数插入，phead就是pso
	ListInsert(phead, x);
}

//尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);//哨兵位不能为空

	////哨兵位不能删
	////assert(phead->next != phead);
	//if (phead->next == NULL)
	//{
	//	return;
	//}

	////遍历链表
	//LTNode* tail = phead->prev;
	//LTNode* tailprev = tail->prev;

	////让最后一个结点和前一个结点断开
	//tailprev->next = phead;
	////让前一个结点和哨兵位结点成循环
	//phead->prev = tailprev;

	////释放
	//free(tail);
	////置空 
	//tail = NULL;



	//使用Erase函数，删除尾结点，不是删除哨兵位
	ListErase(phead->prev);
}

//打印链表
void ListPrint(LTNode* phead)
{
	assert(phead);//哨兵位不能为空

	//遍历指针，phead是哨兵位，不存储数据
	LTNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

//头插
void ListPushFront(LTNode* phead, LTDateType x)
{
	assert(phead);//哨兵位不能为空

	////创建结点
	//LTNode* newnode = BuyListNode(x);

	//LTNode* next = phead->next;

	////连接phead和newnode
	//phead->next = newnode;
	//newnode->prev = phead;

	////让next和newnode连接
	//next->prev = newnode;
	//newnode->next = next;



	//采用Insert函数插入，phead->next才是pos
	ListInsert(phead->next, x);
}

//头删
void ListPopFront(LTNode* phead)
{
	assert(phead);//哨兵位不能为空
	////哨兵位不能删
	//if (phead->next == phead)
	//{
	//	return;
	//}

	//LTNode* next = phead->next;

	//phead->next = next->next;
	//next->next->prev = phead;

	//free(next);
	//next = NULL;



	//使用Erase函数，删除头结点而不是哨兵位
	ListErase(phead->next);

}

//查找
LTNode* ListFind(LTNode* phead, LTDateType x)
{
	assert(phead);//链表为空不能查找

	//phead为哨兵位，应该是下一个结点开始查找
	LTNode* cur = phead->next;

	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	//找不到
	return NULL;
}

//在pos位置前插入,不用管哨兵位的头结点
void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);//待插入位置不能为空

	//创建结点
	LTNode* newnode = BuyListNode(x);

	LTNode* prev = pos->prev;
	
	newnode->prev = prev;
	prev->next = newnode;

	newnode->next = pos;
	pos->prev = newnode;
}

//删除pos位置
void ListErase(LTNode* pos)
{
	assert(pos);//待删位置不能为空

	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;
	
	//将pos前后连接
	posprev->next = posnext;
	posnext->prev = posprev;

	//释放pos
	free(pos);
	//这里置空不置空都不会怎么样，因为这里只是实参的拷贝，最后还是要在外面置空
	pos = NULL;
}

//销毁链表
void ListDestroy(LTNode* phead)
{
	assert(phead);//链表都不存在，不能销毁

	LTNode* cur = phead->next;

	while (cur != phead)
	{
		//在循环里创建方便移动
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(cur);
	//这里置空不置空都不会怎么样，因为这里只是实参的拷贝，最后还是要在外面置空
	cur = NULL;
}