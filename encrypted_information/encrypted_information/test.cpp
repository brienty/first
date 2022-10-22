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
        journey[p]++;//ͳ��ÿһ�������ֵĴ���
    }
    cnt[p]++;//ͳ��Ҷ�ӽڵ���ֵĴ���
}

int query(string s)
{
    int  p = 0, res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        int u = s[i] - '0';
        if (!son[p][u]) return res;//��M��N��ʱ����ô�������ǽ������ǰ׺�����ؼ��������ǽ������ǰ׺����
        p = son[p][u];
        res += cnt[p];
    }
    return res + journey[p] - cnt[p];//��M��N��ʱ
    /*
    �磺
    ������Ϊ0 1 0   1   1 0 0   1 1 0
    ������Ϊ1 1
    ��ʱ���ܵ�һ��1��ѭ���ڱ�resͳ����һ�Σ����ڶ���1��journeyͳ����һ�Σ�����cntû��ͳ�Ƶ��ڶ���1��
    �������res�����˽�������110ǰ׺�����������journey������1��11ǰ׺�����������cnt����0�ˣ�������û��ͳ�Ƶ���
    �����res+journey������������ټ���һ��11����journey���ֶ�ͳ����һ����������Ϊ11��������Ϊ11
    ��res+journey�͵���4�ˣ���Ϊresͳ����1�������11�������journey��ͳ����11��110����������ֻҪͳ��һ��11
    ������Ҫ��ȥcnt��ͳ�Ƶ�11��Ӧ����3�Ŷԣ���Ӧ����4.
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