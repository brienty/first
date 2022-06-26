#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


//���������������Ч��
inline void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//���ϵ�������ʱ�临�Ӷ���O(NlogN)
// ���Ҫʹ�����ô��Σ���Ϊ�������Ҫ��ԭ����ı���������Ԫ�ظ���������
// ����[]�����ȼ�����&���������С���ţ����߱�����������������
void AdjustUp(int (&arr) [13], int& child)
{
    int parent = (child - 1) / 2;
    //�������parent�Ǵ���0�Ļ��ľͻ����±�Ϊ0��Ԫ��
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


//���µ�������ʱ�临�Ӷ���O(N)
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
	//����ѣ���һ�֣����ϵ���������
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(arr, i);
	}*/
	//����ѣ��ڶ��֣����µ���������
    /*�������µ�������Ҫ������鱾�����Ƕ�
    ����������ô�ĩβ��ʼ�����µ������������һ���±�ĸ��ڵ㿪ʼ��ע��0ҲҪ*/
    //���һ�����ĸ���
    int parent = (n - 1 - 1) / 2;
    while (parent >= 0)
    {
        AdjustDown(arr, n, parent);
        --parent;
    }
    //ȷ�����λ�õ�ͬʱҲ�������С
    int end = n - 1;
    while (end > 0)
    {
        //��β����
        swap(arr[0], arr[end]);
        //���������
        AdjustDown(arr, end, 0);
        --end;
    }
}

int main()
{

	int arr[] = { 2,3,1,6,4,76,34,65,24,12,0,22,11 };
    int num = sizeof(arr) / sizeof(arr[0]);
	Test(arr, num);
    //��ӡ���õĶ�
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
	return 0;
}