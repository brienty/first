#define _CRT_SECURE_NO_WARNINGS 1
int trailingZeroes(int n) {
    int num = 0;
    //ֻ��Ҫͳ5�ĸ�������
    while (n >= 5)
    {
        n /= 5;
        num += n;
    }
    return num;
}
#include <iostream>
using namespace std;

int main() {
    double d = 0.0;
    cin >> d;
    cout << (int)(d + 0.5) << endl;
}