#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

//初始化接口
void HeapInit(HP* php)
{
	assert(php);

	php->arr = NULL;
	php->capacity = php->size = 0;
}

//堆销毁接口
void HeapDestroy(HP* php)
{
	assert(php);
	
	//销毁数组
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

//向上调整
void AdjustUp(HPDataType* arr, size_t child)
{
	//父节点
	HPDataType parent = (child - 1) / 2;
	//交换
	while (child > 0)//用child控制，parent会死循环
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

	//扩容
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
	//需要将孩子穿过去，注意size是在最后一个位置的后一个位置
	AdjustUp(php->arr, php->size-1);
}


void AdjustDown(HPDataType* arr, size_t parent, size_t size)
{
	//假设左孩子最小
	HPDataType child = (parent * 2) + 1;

	//使用child控制，parent会越界
	while (child < size)
	{
		//如果右孩子更小则让右孩子去比较，注意右孩子是否存在
		if (arr[child] > arr[child + 1] && child + 1 < size)
		{
			++child;
		}

		//将父亲和孩子比较，父亲更大则交换
		if (arr[parent] > arr[child])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = (parent * 2) - 1;
		}
		//当出现父亲小于孩子时，说明不用往下遍历了
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	//堆不能为空
	assert(php->size > 0);
	//首尾元素的交换
	HPDataType temp = php->arr[0];
	php->arr[0] = php->arr[php->size - 1];
	php->arr[php->size - 1] = temp;
	//删除交换后的尾元素
	--php->size;

	//向下调整
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
	//得要有元素
	assert(php->size > 0);
	
	return php->arr[0];
}