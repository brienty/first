#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const int N = 10010;//10000个整数
int f[N] = { 1, 1, 2 };//计算发现是斐波那契数列

int main()
{
    //将前一万个斐波那契数列存起来，并只取最后的四位
    for (int i = 3; i < N; ++i)
    {
        f[i] = (f[i - 1] + f[i - 2]) % 10000;
    }
    //输入并判断
    int n = 0;
    while (cin >> n)
    {
        int x = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            //“%04d”的作用是输出长度不少于4位，少于用0b填充
            printf("%04d", f[x]);
        }
        cout << endl;
    }
    return 0;
}