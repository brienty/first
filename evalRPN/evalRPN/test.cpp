#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


int evalRPN(vector<string>& tokens) {
    stack<long long> st;//使用longlong存储数字防止越界
    for (const auto& str : tokens)
    {
        //等于符号位则取栈顶元素进行运算
        if (str == "+" || str == "-" || str == "*" || str == "/")
        {
            long long right = st.top();//第一个应该是右操作数
            st.pop();
            long long left = st.top();//第二个是左操作数
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
            st.push(stoi(str));//将字符串转换成整形进行存储
        }
    }
    long long  calc = st.top();//将最后的结果存储并返回
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