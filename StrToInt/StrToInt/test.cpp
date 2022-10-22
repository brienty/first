#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int StrToInt(string str) {
    int flag = 0;
    long long sum = 0;
    int j = 0;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        if (str[0] == '-')
        {
            flag = 1;
        }
        if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
            return 0;
        if (str[i] != '-' && str[i] != '+' && (str[i] >= '0' && str[i] <= '9'))
        {
            sum += (str[i] - '0') * pow(10, j);
            ++j;
        }
    }
    if (flag)
        return -sum;
    return sum;
}