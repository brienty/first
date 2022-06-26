#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//小堆
typedef int HPDataType;
//创建堆结构体
typedef struct Heap
{
	HPDataType* arr;//数组存储
	size_t capacity;
	size_t size;
}HP;

//初始化堆
void HeapInit(HP* php);
//销毁堆
void HeapDestroy(HP* php);
//交换
void swap(HPDataType* pa, HPDataType* pb);
//插入堆，后面插入
void HeapPush(HP* php, HPDataType x);
//删除堆元素，第一个元素
void HeapPop(HP* php);
//判空
bool HeapEmpty(HP* php);
//堆的大小
size_t HeapSize(HP* php);
//返回堆顶元素
HPDataType HeapTop(HP* php);