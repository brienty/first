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
        cnt[p]++;//ͳ����������
    }
}

bool query(char* str)
{
    int p = 0;
    for (int i = 0; str[i]; ++i)
    {
        int u = str[i] - '0';
        if (cnt[son[p][u]] == 1) return false;//�������ֻ������һ�Σ���ô���������Ҳ��ֻ������һ�Σ�˵������ǰ׺
        p = son[p][u];
    }
    return true;//��������ˣ�˵����������>=2����ô����ǰ׺�ַ�����
}


int main()
{
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        //�������룬�ǵ�Ҫ������ݣ���Ȼ�����
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        idx = 0;

        //�����ݴ洢�����뵽trie��
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s[i]);
            insert(s[i]);
        }

        //�ж��Ƿ���ǰ׺�ַ���
        int flag = 0;
        for (int i = 0; i < n; ++i)
        {
            if (query(s[i]))
                flag = 1;
        }

        //flag����1˵������ǰ׺�ַ��������򲻴���
        if (flag == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}