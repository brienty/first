#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        //�����ߵı���
        if (i % 7 == 0) {
            ++count;
        }
        //���������к�����
        else {
            int num = i;
            while (num) {
                int number = num % 10;
                //�����к����߼��ɽ���ѭ������ֹ�ظ�����
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