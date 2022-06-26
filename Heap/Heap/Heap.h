#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//С��
typedef int HPDataType;
//�����ѽṹ��
typedef struct Heap
{
	HPDataType* arr;//����洢
	size_t capacity;
	size_t size;
}HP;

//��ʼ����
void HeapInit(HP* php);
//���ٶ�
void HeapDestroy(HP* php);
//����
void swap(HPDataType* pa, HPDataType* pb);
//����ѣ��������
void HeapPush(HP* php, HPDataType x);
//ɾ����Ԫ�أ���һ��Ԫ��
void HeapPop(HP* php);
//�п�
bool HeapEmpty(HP* php);
//�ѵĴ�С
size_t HeapSize(HP* php);
//���ضѶ�Ԫ��
HPDataType HeapTop(HP* php);