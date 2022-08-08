#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

string addStrings(string num1, string num2) {
    //双尾指针
    int end1 = num1.size() - 1;
    int end2 = num2.size() - 1;
    //进位
    int carry = 0;
    //存储加好的值
    string temp;
    while (end1 >= 0 || end2 >= 0) {
        int n1 = 0;
        int n2 = 0;
        if (end1 >= 0) {
            n1 = num1[end1--] - '0';
        }
        else {
            n1 = 0;
        }
        if (end2 >= 0) {
            n2 = num2[end2--] - '0';
        }
        else {
            n2 = 0;
        }
        int sum = n1 + n2 + carry;
        if (sum > 9) {
            carry = 1;
            sum %= 10;
        }
        else {
            carry = 0;
        }
        temp.insert(0, 1, sum + '0');
    }

    if (carry) {
        temp.insert(0, 1, '1');
    }

    return temp;
}

int main()
{
    string num1("9");
    string num2("999");
    cout << addStrings(num1, num2);
	return 0;
}