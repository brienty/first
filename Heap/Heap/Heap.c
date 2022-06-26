#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//��ʼ���ӿ�
void HeapInit(HP* php)
{
	assert(php);

	php->arr = NULL;
	php->capacity = php->size = 0;
}

//�����ٽӿ�
void HeapDestroy(HP* php)
{
	assert(php);
	
	//��������
	free(php->arr);

	php->arr = NULL;
	php->capacity = php->size = 0;
}

void swap(HPDataType* pa, HPDataType* pb)
{
	HPDataType temp = *pa;
	*pa = *pb;
	*pb = temp;
}

//���ϵ���
void AdjustUp(HPDataType* arr, size_t child)
{
	//���ڵ�
	HPDataType parent = (child - 1) / 2;
	//����
	while (child > 0)//��child���ƣ�parent����ѭ��
	{
		if (arr[parent] > arr[child])
		{
			swap(&arr[parent], &arr[child]);
		}

		child = parent;
		parent = (child - 1) / 2;
	}
}

void  HeapPush(HP* php, HPDataType x)
{
	assert(php);

	//����
	if (php->size == php->capacity)
	{
		size_t newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* temp = (HPDataType*)realloc(php->arr, sizeof(HPDataType) * newcapacity);
		assert(temp);
		php->arr = temp;
		php->capacity = newcapacity;
	}

	php->arr[php->size] = x;
	++php->size;
	//��Ҫ�����Ӵ���ȥ��ע��size�������һ��λ�õĺ�һ��λ��
	AdjustUp(php->arr, php->size-1);
}


void AdjustDown(HPDataType* arr, size_t parent, size_t size)
{
	//����������С
	HPDataType child = (parent * 2) + 1;

	//ʹ��child���ƣ�parent��Խ��
	while (child < size)
	{
		//����Һ��Ӹ�С�����Һ���ȥ�Ƚϣ�ע���Һ����Ƿ����
		if (arr[child] > arr[child + 1] && child + 1 < size)
		{
			++child;
		}

		//�����׺ͺ��ӱȽϣ����׸����򽻻�
		if (arr[parent] > arr[child])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = (parent * 2) - 1;
		}
		//�����ָ���С�ں���ʱ��˵���������±�����
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	//�Ѳ���Ϊ��
	assert(php->size > 0);
	//��βԪ�صĽ���
	HPDataType temp = php->arr[0];
	php->arr[0] = php->arr[php->size - 1];
	php->arr[php->size - 1] = temp;
	//ɾ���������βԪ��
	--php->size;

	//���µ���
	AdjustDown(php->arr, 0, php->size);
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->size == 0;
}

size_t HeapSize(HP* php)
{
	assert(php);

	return php->size;
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	//��Ҫ��Ԫ��
	assert(php->size > 0);
	
	return php->arr[0];
}