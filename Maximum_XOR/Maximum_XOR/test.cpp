#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int son[N * 31][2], idx;
int a[N], n;

void insert(int x)
{
    int p = 0;//��һλ
    //�Ӹ�λ��ʼ����
    for (int i = 30; i >= 0; --i)
    {
        int u = x >> i & 1;//�鿴��ǰλ��0����1
        if (!son[p][u]) son[p][u] = ++idx;//�����ڸ��ӽڵ���һ��λ��
        p = son[p][u];//�ߵ���һ�����
    }
}

int query(int x)
{
    int res = 0, p = 0;//�洢���
    //�Ӹ�λ��ʼ����
    for (int i = 30; i >= 0; --i)
    {
        int u = x >> i & 1;//�鿴��ǰλ��0����1
        //���ڲ�һ����λ������һ��λ
        if (son[p][!u])
        {
            p = son[p][!u];
            res = (res << 1) + 1;
        }
        //����ֻ����ͬλ��
        else
        {
            p = son[p][u];
            res = (res << 1) + 0;
        }
    }
    //�������ֵ
    return res;
}

int main()
{
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, query(a[i]));
    cout << res << endl;
    return 0;
}