#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 1000010;//��������ݸ���

//q�洢���ݣ�tmp��ʱ�洢����õ�����
int q[N], tmp[N];

int n = 0;

void merge_sort(int q[], int l, int r)
{
    if (l == r) return;//�ݹ�����жϵ���������ֻʣһ�����ݾͲ���������
    int mid = l + r >> 1;//��ȡÿ��������м��±�ֵ

    //����
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);//��һ������ֳɶ԰�������������䣬�ֱ��������

    //�鲢��˫ָ���������������������ݣ�ȡС����ǰ�ţ���������
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    //������һ�����仹������ʱֱ�ӽ���������ż���
    while (i <= mid) tmp[k++] = q[i++];
    while (j <= r) tmp[k++] = q[j++];

    //��ֵ���q��
    for (int i = l, j = 0; l <= r; ++i, ++j) q[i] = tmp[j];
}

int main()
{
    //����
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    //����
    merge_sort(q, 0, n - 1);
    //���
    for (int i = 0; i < n; ++i) printf("%d ", q[i]);
    return 0;
}