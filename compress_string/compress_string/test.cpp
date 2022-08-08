#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

string compressString(string S) {
    int length = S.size();
    string temp;
    int count = 0;
    int begin = 0, end = 0;
    for (int i = 0; S[begin] != '\0'; ++i) {
        if (S[begin] == S[end]) {
            ++count;
            ++end;
        }
        else {
            begin = end;
            temp += S[end - 1];
            temp += to_string(count);
            count = 0;
        }
    }

    if (temp.size() >= S.size())
        return S;
    else
        return temp;
}

int main()
{
    string S("bb");
    cout << compressString(S);
	return 0;
}