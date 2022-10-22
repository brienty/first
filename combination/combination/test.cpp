#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//��Ŀ���ӣ�https://leetcode.cn/problems/letter-combinations-of-a-phone-number

//�洢Ӣ����ĸ
string _digits[10] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
void combination(string digits, string tempcombine, int num, vector<string>& combine)
{
    //�������ַ����������ݹ����
    if (num == digits.size())
    {
        //�����������ַ�����combine
        combine.push_back(tempcombine);
        return;
    }
    //����num�±���ȡ�������ַ�
    int n = digits[num] - '0';
    //ȡ�������ַ�����Ӧ���ַ���
    string letterstring = _digits[n];
    //���������ַ�����Ӧ���ַ���
    for (auto e : letterstring)
    {
        //ֱ��ʹ�üӺŽ��ַ�¼��tempcombine��ע�����num
        combination(digits, tempcombine + e, num + 1, combine);
    }
}

vector<string> letterCombinations(string digits) {
    //�洢���������ַ�
    string tempcombine;
    //�洢ȫ������Ͻ��
    vector<string> combine;
    //�������ַ���Ϊ��ʱ��ֱ�ӷ���combine
    if (digits.empty())
    {
        return combine;
    }
    //num���ڱ��������ַ�����
    int num = 0;
    //���õݹ�ķ�ʽ����
    combination(digits, tempcombine, num, combine);
    return combine;
}

int main()
{
    vector<string> s = letterCombinations("23");
    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
	return 0;
}