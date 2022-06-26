#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

//重定义类型，方便更改
typedef int SLDataType;

//动态顺序表的定义，为了方便后续使用，重定义
typedef struct SeqList
{
	SLDataType* a;
	int sz;
	int capacity;
}SL, SeqList;

//初始化顺序表
void SeqListInit(SeqList* psl);

//顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x);

//顺序表尾删
void SeqListPopBack(SeqList* psl);

//顺序表销毁
void SeqListDestroy(SeqList* psl);

//打印顺序表
void SeqListPrint(SeqList* psl);

//增加容量
void SeqListCheckcapacity(SeqList* psl);

//顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x);

//顺序表头删
void SeqListPopFront(SeqList* psl);

//随机插入
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);

//删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos);

//查找pos位置上的值
int SeqListFind(SeqList* psl, SLDataType x);

//修改pos位置上的值
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);