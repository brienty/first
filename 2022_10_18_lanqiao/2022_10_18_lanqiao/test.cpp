#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 700010;
int a[N], st[N], tmp[N], tt;
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    for (int i = 0; i < n; ++i)
    {
        while (tt > 0 && a[st[tt]] <= a[i]) tt--;
        printf("%d ", ((tt > 0) ? (st[tt] + 1) : -1));
        st[++tt] = i;
    }
    cout << endl;

    tt = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        while (tt > 0 && a[st[tt]] <= a[i]) tt--;
        tmp[j++] = ((tt > 0) ? (st[tt] + 1) : -1);
        st[++tt] = i;
    }
    for (int i = n - 1; i >= 0; --i) printf("%d ", tmp[i]);
    return 0;
}


#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000010;
int a[N], q[N], max1[N], min1[N], hh, tt = -1;
int n, k;

//典型的滑动窗口问题，需要注意的是即使i没达到滑动窗口的大小也需要统计当前窗口内的最大/最小值
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    //统计最大的
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        max1[j++] = a[q[hh]];
    }

    //统计最小的
    j = 0, hh = 0, tt = -1;
    for (int i = 0; i < n; ++i)
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        min1[j++] = a[q[hh]];
    }

    //计算最大差值
    int Max = -1;
    for (int i = 0; i < n; ++i)
    {
        Max = max(max1[i] - min1[i], Max);
    }
    cout << Max << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 500010;
int q[N];

int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &q[i]);
    sort(q, q + n);
    for (int i = 0; i < n; ++i) printf("%d ", q[i]);
    printf("\n");
    for (int i = n - 1; i >= 0; --i) printf("%d ", q[i]);
    return 0;
}

#include <iostream>
using namespace std;

//辗转相除法
int main()
{
    int n = 0;
    scanf("%d", &n);
    while (n--)
    {
        int n1 = 0, n2 = 0;
        scanf("%d%d", &n1, &n2);
        int n3 = n1 % n2;
        while (n2)
        {
            n3 = n1 % n2;
            n1 = n2;
            n2 = n3;
        }
        cout << n1 << endl;
    }
    return 0;
}