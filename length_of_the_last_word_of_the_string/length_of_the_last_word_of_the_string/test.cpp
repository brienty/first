#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    size_t n = s.find_last_of(' ', s.size());
    if (n == string::npos)
    {
        cout << s.size();
    }
    else
    {
        string sub = s.substr(n + 1);
        cout << sub.size();
    }
    return 0;
}