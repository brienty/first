#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using  namespace std;

const int N = 100010;

int son[N][10], cnt[N], idx;
int t, n;
char s[N][10];

void insert(char* str)
{
    int p = 0;
    for (int i = 0; str[i]; ++i)
    {
        int u = str[i] - '0';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;//统计所有数字
    }
}

bool query(char* str)
{
    int p = 0;
    for (int i = 0; str[i]; ++i)
    {
        int u = str[i] - '0';
        if (cnt[son[p][u]] == 1) return false;//如果数字只出现了一次，那么后面的数字也就只出现了一次，说明不是前缀
        p = son[p][u];
    }
    return true;//最后走完了，说明所有数字>=2，那么就是前缀字符串了
}


int main()
{
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        //连续输入，记得要清空数据，不然会溢出
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        idx = 0;

        //将数据存储并插入到trie树
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s[i]);
            insert(s[i]);
        }

        //判断是否有前缀字符串
        int flag = 0;
        for (int i = 0; i < n; ++i)
        {
            if (query(s[i]))
                flag = 1;
        }

        //flag等于1说明存在前缀字符串，否则不存在
        if (flag == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}