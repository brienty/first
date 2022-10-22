#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

const int N = 500010;
int son[N][2], journey[N], cnt[N], idx;
int n, m;

void insert(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        int u = s[i] - '0';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        journey[p]++;//统计每一个结点出现的次数
    }
    cnt[p]++;//统计叶子节点出现的次数
}

int query(string s)
{
    int  p = 0, res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        int u = s[i] - '0';
        if (!son[p][u]) return res;//当M比N长时，那么加密码是解密码的前缀，返回加密码中是解密码的前缀即可
        p = son[p][u];
        res += cnt[p];
    }
    return res + journey[p] - cnt[p];//当M比N短时
    /*
    如：
    加密码为0 1 0   1   1 0 0   1 1 0
    解密码为1 1
    此时解密第一个1在循环内被res统计了一次，而第二个1被journey统计了一次，但是cnt没有统计到第二个1。
    如果返回res就少了解密码是110前缀的情况，返回journey加密码1是11前缀的情况，返回cnt就是0了，两个都没有统计到！
    如果是res+journey，假设加密码再加入一个11，那journey就又多统计了一个，加密码为11，解密码为11
    那res+journey就等于4了，因为res统计了1的情况和11的情况，journey又统计了11和110，但是我们只要统计一次11
    所以需要减去cnt多统计的11，应该是3才对，不应该是4.
    */
}

int main()
{
    cin.tie(0);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        string s;
        int tmp = 0;
        scanf("%d", &tmp);
        for (int j = 0; j < tmp; ++j)
        {
            char c = 0;
            cin >> c;
            s += c;
        }
        insert(s);
    }

    for (int i = 0; i < m; ++i)
    {
        string s;
        int tmp = 0;
        scanf("%d", &tmp);
        for (int j = 0; j < tmp; ++j)
        {
            char c = 0;
            cin >> c;
            s += c;
        }
        cout << query(s) << endl;;
    }
    return 0;
}