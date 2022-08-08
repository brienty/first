#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//复用加法，效率低
//string addStrings(const string& num1, const string& num2) {
//    //双尾指针
//    int end1 = num1.size() - 1;
//    int end2 = num2.size() - 1;
//    //进位
//    int carry = 0;
//    //存储加好的值
//    string temp;
//    while (end1 >= 0 || end2 >= 0) {
//        int n1 = 0;
//        int n2 = 0;
//        if (end1 >= 0) {
//            n1 = num1[end1--] - '0';
//        }
//        else {
//            n1 = 0;
//        }
//        if (end2 >= 0) {
//            n2 = num2[end2--] - '0';
//        }
//        else {
//            n2 = 0;
//        }
//        int sum = n1 + n2 + carry;
//        if (sum > 9) {
//            carry = 1;
//            sum %= 10;
//        }
//        else {
//            carry = 0;
//        }
//        temp.insert(0, 1, sum + '0');
//    }
//
//
//    if (carry) {
//        temp.insert(0, 1, '1');
//    }
//
//
//    return temp;
//}
//
//string multiply(string num1, string num2) {
//    //存储每一位相乘的结果
//    string temp;
//
//    //用来存储每一位乘完相加的结果
//    string addstr("0");
//
//    //当有一个为0时，直接返回0
//    if (num1 == addstr || num2 == addstr)
//        return addstr;
//
//    int end2 = num2.size() - 1;
//    for (size_t i = 0; i < num2.size(); ++i)
//    {
//        //乘法的处理
//        int end1 = num1.size() - 1;
//        int carry = 0;
//        int n2 = num2[end2--] - '0';
//        while (end1 >= 0)
//        {
//            int n1 = num1[end1--] - '0';
//            int sum = n1 * n2 + carry;
//            if (sum > 9)
//            {
//                carry = sum / 10;;
//                sum %= 10;
//            }
//            else
//            {
//                carry = 0;
//            }
//            temp.insert(0, 1, sum + '0');
//            sum = 0;
//        }
//        //乘完以后从十位开始需要加0
//        int j = i;
//        while (j)
//        {
//            temp += '0';
//            --j;
//        }
//        //处理进位仍有数未加上的情况
//        if (carry)
//        {
//            temp.insert(0, 1, carry + '0');
//        }
//        //将每一个乘完的字符串相加起来
//        addstr = addStrings(temp, addstr);
//        //需要将temp清空，下一次循环重新使用
//        temp.clear();
//    }
//
//    return addstr;
//}

//效率更高
string multiply(string num1, string num2) {
    //处理等于0和本身的情况
    if (num1 == "0" || num2 == "0")
        return "0";
    int n1 = num1.size();
    int n2 = num2.size();
    //开好最大空间数，数字相乘的位数最大长度不会超过两长度相加的长度
    string s(n1 + n2, '0');
    for (int i = n2 - 1; i >= 0; --i)
    {
        int carry = 0;
        for (int j = n1 - 1; j >= 0; --j)
        {
            //s[i+j+1]-'0'随下标的改变会是一位位的减少，即达到竖式相乘的效果
            int sum = (num2[i] - '0') * (num1[j] - '0') + (s[i + j + 1] - '0') + carry;
            carry = sum / 10;
            int number = sum % 10;
            s[i + j + 1] = number + '0';
        }
        //处理进位还有未处理的情况
        if (carry)
            s[i] = carry + '0';
    }

    //将最前多余的0清除
    int i = 0;
    while (s[i] == '0')
    {
        ++i;
    }
    return s.substr(i);
}

int main()
{
    string num1("9");
    string num2("9");
    cout << multiply(num1, num2);
	return 0;
}