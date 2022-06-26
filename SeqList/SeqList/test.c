#define _CRT_SECURE_NO_WARNINGS 1 
#include "SeqList.h"

/*
	˳���Ҫ��
	�洢�����ݴ�0��ʼ�����������洢
*/

//Ϊ�˷������͵ı任���ض�������

//����β��βɾ
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);//����ַ
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

//����ͷ��ͷɾ
void TestSeqList2()
{
	SeqList s;
	SeqListInit(&s);//����ַ
	/*
	* �����ȳ�ʼ������Ϊ��
	* ˳����еĿռ�տ�ʼ�����ֵ���Ǿ�û�а취�������ַ��realloc
	* realloc�ǶԵ�һ��������ʾ�����ݿռ���е���
	* ��ʹ��˳�����������֮��  �Ȱ�˳����ʼ����   ��ʼ����ʱ�����ô�к��ʿռ��˾ͽ�aֵΪNULL
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

//�������й���
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
	//��������ﴫ��ȥ���Ǿͳɶ���ָ�룬������Ҫ���ν�����

	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();

	return 0;
}