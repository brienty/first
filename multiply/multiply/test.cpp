#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//���üӷ���Ч�ʵ�
//string addStrings(const string& num1, const string& num2) {
//    //˫βָ��
//    int end1 = num1.size() - 1;
//    int end2 = num2.size() - 1;
//    //��λ
//    int carry = 0;
//    //�洢�Ӻõ�ֵ
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
//    //�洢ÿһλ��˵Ľ��
//    string temp;
//
//    //�����洢ÿһλ������ӵĽ��
//    string addstr("0");
//
//    //����һ��Ϊ0ʱ��ֱ�ӷ���0
//    if (num1 == addstr || num2 == addstr)
//        return addstr;
//
//    int end2 = num2.size() - 1;
//    for (size_t i = 0; i < num2.size(); ++i)
//    {
//        //�˷��Ĵ���
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
//        //�����Ժ��ʮλ��ʼ��Ҫ��0
//        int j = i;
//        while (j)
//        {
//            temp += '0';
//            --j;
//        }
//        //�����λ������δ���ϵ����
//        if (carry)
//        {
//            temp.insert(0, 1, carry + '0');
//        }
//        //��ÿһ��������ַ����������
//        addstr = addStrings(temp, addstr);
//        //��Ҫ��temp��գ���һ��ѭ������ʹ��
//        temp.clear();
//    }
//
//    return addstr;
//}

//Ч�ʸ���
string multiply(string num1, string num2) {
    //�������0�ͱ�������
    if (num1 == "0" || num2 == "0")
        return "0";
    int n1 = num1.size();
    int n2 = num2.size();
    //�������ռ�����������˵�λ����󳤶Ȳ��ᳬ����������ӵĳ���
    string s(n1 + n2, '0');
    for (int i = n2 - 1; i >= 0; --i)
    {
        int carry = 0;
        for (int j = n1 - 1; j >= 0; --j)
        {
            //s[i+j+1]-'0'���±�ĸı����һλλ�ļ��٣����ﵽ��ʽ��˵�Ч��
            int sum = (num2[i] - '0') * (num1[j] - '0') + (s[i + j + 1] - '0') + carry;
            carry = sum / 10;
            int number = sum % 10;
            s[i + j + 1] = number + '0';
        }
        //�����λ����δ��������
        if (carry)
            s[i] = carry + '0';
    }

    //����ǰ�����0���
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