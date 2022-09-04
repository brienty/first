#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        //处理七的倍数
        if (i % 7 == 0) {
            ++count;
        }
        //处理数字中含有七
        else {
            int num = i;
            while (num) {
                int number = num % 10;
                //数字中含有七即可结束循环，防止重复计算
                if (number == 7) {
                    ++count;
                    break;
                }
                num /= 10;
            }
        }
    }
    cout << count;
}