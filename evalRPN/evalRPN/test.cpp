#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


int evalRPN(vector<string>& tokens) {
    stack<long long> st;//ʹ��longlong�洢���ַ�ֹԽ��
    for (const auto& str : tokens)
    {
        //���ڷ���λ��ȡջ��Ԫ�ؽ�������
        if (str == "+" || str == "-" || str == "*" || str == "/")
        {
            long long right = st.top();//��һ��Ӧ�����Ҳ�����
            st.pop();
            long long left = st.top();//�ڶ������������
            st.pop();
            if (str[0] == '+')
            {
                st.push(left + right);
            }
            else if (str[0] == '-')
            {
                st.push(left - right);
            }
            else if (str[0] == '*')
            {
                st.push(left * right);
            }
            else
            {
                st.push(left / right);
            }
        }
        else
        {
            st.push(stoi(str));//���ַ���ת�������ν��д洢
        }
    }
    long long  calc = st.top();//�����Ľ���洢������
    return calc;
}

int main()
{
    vector<string> tokens;
    tokens.push_back("10");
    tokens.push_back("6");
    tokens.push_back("9");
    tokens.push_back("3");
    tokens.push_back("+");
    tokens.push_back("-11");
    tokens.push_back("*");
    tokens.push_back("/");
    tokens.push_back("*");
    tokens.push_back("17");
    tokens.push_back("+");
    tokens.push_back("5");
    tokens.push_back("+");
    cout << evalRPN(tokens) << endl;
	return 0;
}