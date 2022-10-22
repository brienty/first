#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 1000010;//排序的数据个数

//q存储数据，tmp暂时存储排序好的数据
int q[N], tmp[N];

int n = 0;

void merge_sort(int q[], int l, int r)
{
    if (l == r) return;//递归结束判断的条件，即只剩一个数据就不用排序了
    int mid = l + r >> 1;//获取每个区间的中间下标值

    //排序
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);//把一个区间分成对半的左右两边区间，分别进行排序

    //归并，双指针做法处理左右两边数据，取小的往前放，大的往后放
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    //当其中一个区间还有数据时直接将数据往后放即可
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    //将值存回q中
    for (int i = l, j = 0; l <= r; ++i, ++j) q[i] = tmp[j];
}

int main()
{
    //输入
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    //排序
    merge_sort(q, 0, n - 1);
    //输出
    for (int i = 0; i < n; ++i) printf("%d ", q[i]);
    return 0;
}