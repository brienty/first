#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//��ʼ��˳���
void SeqListInit(SeqList* psl)
{
	assert(psl);//�п�
	psl->a = NULL;
	psl->sz = 0;
	psl->capacity = 0;
}

void SeqListCheckcapacity(SeqList* psl)
{
	assert(psl);//�п�
	//���� 
	if (psl->sz == psl->capacity)
	{
		size_t newcapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;//Ϊ�˷�ֹ��ʼ����ֵΪ�㣬����ֱ�ӳ���2����������ݻ�ʧ��
		SLDataType* temp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * newcapacity);
		if (temp == NULL)
		{
			printf("open failed\n");
			exit(-1);//�ս���򣬲�������
		}
		else
		{
			psl->a = temp;
			psl->capacity = newcapacity;//�����ݿռ丳ֵ���ɵ�����
		}
	}
}

//˳���β������
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);//�п�
	
	SeqListInsert(psl, psl->sz, x);//����������뺯��
	//������Ҫע�ⲻ����psl->sz-1����Ϊһ��ʼ��sz����0��-1��Խ���ˣ�
}

//ɾ��˳���β��Ԫ��
void SeqListPopBack(SeqList* psl)
{
	assert(psl);//�п�

	SeqListErase(psl, psl->sz - 1);//����ɾ������λ�ú���
}

//����˳���
void SeqListDestroy(SeqList* psl)
{
	assert(psl);//�п�

	//�ͷŲ��ÿ�
	free(psl->a);
	psl->a = NULL;
	//��0
	psl->sz = 0;
	psl->capacity = 0;
}

//��ӡ˳���
void SeqListPrint(SeqList* psl)
{
	assert(psl);//�п�
	int i = 0;
	for (i = 0; i < psl->sz; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

//˳���ͷ������
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);//�п�

	SeqListInsert(psl, 0, x);//��������λ�ò��뺯��
}

//˳���ͷ��ɾ��
void SeqListPopFront(SeqList* psl)
{
	assert(psl);//�п�
	
	SeqListErase(psl, 0);//����ɾ������λ�ú���
}

//C++��׼���±궼���޷�������
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);//���psl

	//����Ƿ�Խ��
	if (pos > psl->sz)
	{
		printf("Խ��\n");
		return;
	}

	//����Ƿ���Ҫ����
	SeqListCheckcapacity(psl);

	//�±�ʹ���޷������Σ�endָ�����Ӧ��Ԫ�غ���
	size_t end = psl->sz;

	//���в��룬�����и�ע���������������������
	//����޷��ź��з�������һ����֣�Ҫע���޷������κ��з��������ڽ��м���ʱ����������
	//���ʹ�õ�ȫ���޷������Σ��Ǿ�Ҫע��end��Խ���������ѭ��
	while (end > pos)
	{
		psl->a[end] = psl->a[end - 1];
		--end;
	}

	psl->a[pos] = x;
	psl->sz++;
}

//ɾ��posλ�õ�����
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);//�п�

	//�ж�Խ��
	if (pos >= psl->sz)
	{
		printf("Խ��\n");
		return;
	}

	size_t begin = pos + 1;

	//��ʼ�ƶ�
	while (begin < psl->sz)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}

	--psl->sz;
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);//�п�

	//����Ѱ�ң������±�
	for (int i = 0; i < psl->sz; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}

	//�Ҳ�������-1������
	return -1;
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);//�п�

	//�ж�Խ��
	if (pos >= psl->sz)
	{
		printf("Խ��\n");
		return;
	}

	psl->a[pos] = x;
}