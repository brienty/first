#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main() {
    int input = 0, num1 = 1, num2 = 1, d = 0;
    cin >> input;
    //������Ϊ1ʱ��ֱ�����0
    if (input == 1) {
        cout << 0;
    }
    else {
        int num3 = 0;
        for (int i = 0; num3 < input; ++i) {
            //��쳲�������
            num3 = num1 + num2;
            num1 = num2;
            num2 = num3;
            //���쳲�������������Ĳ�
            int tmp = abs(input - num3);
            //��һ��d��tmp��һ����
            if (i == 0)
                d = tmp;
            //ֻ�е����߲���С�ſ��Ը�ֵ��d��d������С�Ĳ�
            if (tmp < d)
                d = tmp;
        }
        cout << d;
    }
    return 0;
}