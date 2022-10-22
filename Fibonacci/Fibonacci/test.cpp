#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main() {
    int input = 0, num1 = 1, num2 = 1, d = 0;
    cin >> input;
    //当输入为1时，直接输出0
    if (input == 1) {
        cout << 0;
    }
    else {
        int num3 = 0;
        for (int i = 0; num3 < input; ++i) {
            //求斐波那契数
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
            //求出斐波那契数与输入的差
            int tmp = abs(input - num3);
            //第一次d和tmp是一样的
            if (i == 0)
                d = tmp;
            //只有当两者差最小才可以赋值给d，d即是最小的差
            if (tmp < d)
                d = tmp;
        }
        cout << d;
    }
    return 0;
}