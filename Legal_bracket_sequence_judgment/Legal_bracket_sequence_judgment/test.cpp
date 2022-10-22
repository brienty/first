#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool chkParenthesis(string A, int n) {
    // write code here
    stack<char> s;
    //入栈
    for (int i = 0; i < A.size(); ++i)
    {
        //不是括号返回false
        if (A[i] != '(' && A[i] != ')')
            return false;
        //是(则入栈
        if (A[i] == '(')
            s.push(A[i]);
    }
    //出栈
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == ')')
        {
            //当栈空了但是A中还有括号，那就是无法匹配的括号
            if (s.empty())
                return false;
            //匹配上的删除
            s.pop();
        }
    }
    //栈里还有数据，则说明有括号多出来
    if (!s.empty())
        return false;
    return true;
}

int main()
{
    cout << chkParenthesis("()()(((())))", 12);
    return 0;
}