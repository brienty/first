#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    cin >> num1 >> num2 >> num3 >> num4;
    //����������ֱ�ӷ���
    if ((num1 + num3) % 2 == 1 || (num2 + num4) % 2 == 1)
    {
        cout << "No";
    }
    else
    {
        int A = 0, B = 0, C = 0;
        //��ȡA��B
        A = (num1 + num3) / 2;
        B = (num2 + num4) / 2;
        //����C�������ֵ
        C = B - num2;
        //�����򷵻�
        if (A - B == num1 && B - C == num2 && A + B == num3 && B + C == num4)
            cout << A << " " << B << " " << C;
        else
            cout << "No";
    }
    return 0;
}