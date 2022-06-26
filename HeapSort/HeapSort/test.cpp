#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//采用内联函数提高效率
inline void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//向上调整法，时间复杂度是O(NlogN)
// 如果要使用引用传参，因为这个数组要是原数组的别名，所以元素个数不能少
// 由于[]的优先级高于&，必须加上小括号，告诉编译器这是引用数组
void AdjustUp(int (&arr) [13], int& child)
{
    int parent = (child - 1) / 2;
    //这里如果parent是大于0的话的就会少下标为0的元素
    while (parent >= 0)
    {
        if (arr[parent] < arr[child])
        {
            swap(arr[parent], arr[child]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
}


//向下调整法，时间复杂度是O(N)
void AdjustDown(int (&arr) [13], int& n, int parent)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (arr[child] > arr[child + 1] && child + 1 < n)
        {
            child++;
        }

        if (arr[child] < arr[parent])
        {
            swap(arr[child], arr[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}


void Test(int (&arr) [13], int& n)
{
	//建大堆，第一种，向上调整法建堆
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(arr, i);
	}*/
	//建大堆，第二种，向下调整法建堆
    /*由于向下调整法需要这个数组本来就是堆
    所以这里采用从末尾开始的向下调整法，从最后一个下标的父节点开始，注意0也要*/
    //最后一个结点的父亲
    int parent = (n - 1 - 1) / 2;
    while (parent >= 0)
    {
        AdjustDown(arr, n, parent);
        --parent;
    }
    //确定最后位置的同时也是数组大小
    int end = n - 1;
    while (end > 0)
    {
        //首尾交换
        swap(arr[0], arr[end]);
        //交换完调整
        AdjustDown(arr, end, 0);
        --end;
    }
}

int main()
{

	int arr[] = { 2,3,1,6,4,76,34,65,24,12,0,22,11 };
    int num = sizeof(arr) / sizeof(arr[0]);
	Test(arr, num);
    //打印建好的堆
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
	return 0;
}