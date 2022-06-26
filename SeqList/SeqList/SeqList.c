#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//初始化顺序表
void SeqListInit(SeqList* psl)
{
	assert(psl);//判空
	psl->a = NULL;
	psl->sz = 0;
	psl->capacity = 0;
}

void SeqListCheckcapacity(SeqList* psl)
{
	assert(psl);//判空
	//增容 
	if (psl->sz == psl->capacity)
	{
		size_t newcapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;//为了防止初始化的值为零，不能直接乘以2，下面的扩容会失败
		SLDataType* temp = (SLDataType*)realloc(psl->a, sizeof(SLDataType) * newcapacity);
		if (temp == NULL)
		{
			printf("open failed\n");
			exit(-1);//终结程序，不再运行
		}
		else
		{
			psl->a = temp;
			psl->capacity = newcapacity;//将增容空间赋值给旧的容量
		}
	}
}

//顺序表尾部插入
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);//判空
	
	SeqListInsert(psl, psl->sz, x);//调用任意插入函数
	//这里需要注意不能是psl->sz-1，因为一开始，sz就是0，-1就越界了！
}

//删除顺序表尾部元素
void SeqListPopBack(SeqList* psl)
{
	assert(psl);//判空

	SeqListErase(psl, psl->sz - 1);//调用删除任意位置函数
}

//销毁顺序表
void SeqListDestroy(SeqList* psl)
{
	assert(psl);//判空

	//释放并置空
	free(psl->a);
	psl->a = NULL;
	//置0
	psl->sz = 0;
	psl->capacity = 0;
}

//打印顺序表
void SeqListPrint(SeqList* psl)
{
	assert(psl);//判空
	int i = 0;
	for (i = 0; i < psl->sz; i++)
	{
		printf("%d ", psl->a[i]);
	}
	printf("\n");
}

//顺序表头部插入
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);//判空

	SeqListInsert(psl, 0, x);//调用任意位置插入函数
}

//顺序表头部删除
void SeqListPopFront(SeqList* psl)
{
	assert(psl);//判空
	
	SeqListErase(psl, 0);//调用删除任意位置函数
}

//C++标准中下标都是无符号整形
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);//检查psl

	//检查是否越界
	if (pos > psl->sz)
	{
		printf("越界\n");
		return;
	}

	//检查是否需要扩容
	SeqListCheckcapacity(psl);

	//下标使用无符号整形，end指向最后应该元素后面
	size_t end = psl->sz;

	//进行插入，这里有个注意事项，当除这种以外的情况
	//如果无符号和有符号整形一起出现，要注意无符号整形和有符号整形在进行计算时会整形提升
	//如果使用的全是无符号整形，那就要注意end别越界而导致死循环
	while (end > pos)
	{
		psl->a[end] = psl->a[end - 1];
		--end;
	}

	psl->a[pos] = x;
	psl->sz++;
}

//删除pos位置的数据
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);//判空

	//判断越界
	if (pos >= psl->sz)
	{
		printf("越界\n");
		return;
	}

	size_t begin = pos + 1;

	//开始移动
	while (begin < psl->sz)
	{
		psl->a[begin - 1] = psl->a[begin];
		++begin;
	}

	--psl->sz;
}

int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);//判空

	//遍历寻找，返回下标
	for (int i = 0; i < psl->sz; i++)
	{
		if (psl->a[i] == x)
		{
			return i;
		}
	}

	//找不到返回-1错误码
	return -1;
}

void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);//判空

	//判断越界
	if (pos >= psl->sz)
	{
		printf("越界\n");
		return;
	}

	psl->a[pos] = x;
}