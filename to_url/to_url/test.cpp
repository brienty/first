#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(string S, int length) {
    //确定空格数
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if (S[i] == ' ')
            ++count;
    }
    int newlength = length + count * 2;
    int end1 = length - 1;
    int end2 = newlength - 1;
    while (end1 >= 0) {
        if (S[end1] == ' ') {
            S[end2--] = '0';
            S[end2--] = '2';
            S[end2--] = '%';
            --end1;
        }
        else {
            S[end2] = S[end1];
            --end1;
            --end2;
        }
    }
    S[newlength] = '\0';
    return S;
}

int main()
{
    string S("ds sdfs afs sdfa dfssf asdf             ");
	cout << replaceSpaces(S, 27);
	return 0;
}