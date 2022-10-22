#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool chkParenthesis(string A, int n) {
    // write code here
    stack<char> s;
    //��ջ
    for (int i = 0; i < A.size(); ++i)
    {
        //�������ŷ���false
        if (A[i] != '(' && A[i] != ')')
            return false;
        //��(����ջ
        if (A[i] == '(')
            s.push(A[i]);
    }
    //��ջ
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == ')')
        {
            //��ջ���˵���A�л������ţ��Ǿ����޷�ƥ�������
            if (s.empty())
                return false;
            //ƥ���ϵ�ɾ��
            s.pop();
        }
    }
    //ջ�ﻹ�����ݣ���˵�������Ŷ����
    if (!s.empty())
        return false;
    return true;
}

int main()
{
    cout << chkParenthesis("()()(((())))", 12);
    return 0;
}