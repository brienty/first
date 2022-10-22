#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int son[N * 31][2], idx;
int a[N], n;

void insert(int x)
{
    int p = 0;//下一位
    //从高位开始遍历
    for (int i = 30; i >= 0; --i)
    {
        int u = x >> i & 1;//查看当前位是0还是1
        if (!son[p][u]) son[p][u] = ++idx;//不存在该子节点则开一个位置
        p = son[p][u];//走到下一个结点
    }
}

int query(int x)
{
    int res = 0, p = 0;//存储结果
    //从高位开始遍历
    for (int i = 30; i >= 0; --i)
    {
        int u = x >> i & 1;//查看当前位是0还是1
        //存在不一样的位，走另一个位
        if (son[p][!u])
        {
            p = son[p][!u];
            res = (res << 1) + 1;
        }
        //否则只能走同位的
        else
        {
            p = son[p][u];
            res = (res << 1) + 0;
        }
    }
    //返回最大值
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