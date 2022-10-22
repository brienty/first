#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    string s;
    //输入十进制数
    int in = 0;
    cin >> in;
    //输入转换的进制
    int base = 0;
    cin >> base;
    //先不去关注正负
    int div = abs(in);
    //获取字符
    char n = 0;
    //进制转换
    while (div > 0)
    {
        //存储余数
        int remainder = div % base;
        //余数大于九用字母表示
        if (remainder > 9)
        {
            n = remainder - 10 + 'A';
        }
        //余数小于九用数字表示
        else
        {
            n = remainder + '0';
        }
        //将字符头插进s中
        s.insert(0, 1, n);
        //除去已转换的部分
        div /= base;
    }
    //in等于0直接返回0
    if (in == 0)
    {
        cout << 0;
    }
    else
    {
        //当in小于0时头插一个负号，再输出
        if (in < 0)
        {
            s.insert(0, 1, '-');
            cout << s;
        }
        //否则直接输出
        else
        {
            cout << s;
        }
    }
    return 0;
}