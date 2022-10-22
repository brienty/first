#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                v.push_back(i);
                v.push_back(j);
                return v;
            }
        }
    }
    return v;
}


bool isPalindrome(int x) {
    //С��0һ�����ǻ���
    if (x < 0)
        return false;
    //ת���ַ����ж�
    string s = to_string(x);
    int begin = 0;
    int end = s.size() - 1;
    while (begin < end)
    {
        if (s[begin] != s[end])
            return false;
        ++begin;
        --end;
    }
    return true;
}


int romanToInt(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                sum += 4;
                ++i;
            }
            else if (s[i + 1] == 'X')
            {
                sum += 9;
                ++i;
            }
            else
            {
                sum += 1;
            }
        }
        else if (s[i] == 'V')
        {
            sum += 5;
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                sum += 40;
                ++i;
            }
            else if (s[i + 1] == 'C')
            {
                sum += 90;
                ++i;
            }
            else
            {
                sum += 10;
            }
        }
        else if (s[i] == 'L')
        {
            sum += 50;
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                sum += 400;
                ++i;
            }
            else if (s[i + 1] == 'M')
            {
                sum += 900;
                ++i;
            }
            else
            {
                sum += 100;
            }
        }
        else if (s[i] == 'D')
        {
            sum += 500;
        }
        else
        {
            sum += 1000;
        }
    }
    return sum;
}



string longestCommonPrefix(vector<string>& strs) {
    string tmp;
    //��strsΪ���ַ���ʱ����""
    if (strs.empty())
    {
        return tmp;
    }
    //�ҵ������ַ����еĳ�����С���Ǹ��Ĵ�С
    int count = INT_MAX;//����Ϊ���ε����ֵ�������
    for (int i = 0; i < strs.size(); ++i)
    {
        if (count > strs[i].size())
        {
            count = strs[i].size();
        }
    }
    //�ó�����С�ַ������ַ�����Ϊ�����ַ�������
    for (int i = 0; i < count; ++i)
    {
        int j = 0;
        for (; j < strs.size() - 1; ++j)
        {
            if (strs[j][i] != strs[j + 1][i])
                return tmp;
        }
        tmp += strs[j][i];
    }
    return tmp;
}


int lengthOfLastWord(string s) {
    int end = s.size() - 1;
    //��������Ŀո�
    while (s[end] == ' ')
    {
        --end;
    }
    int count = 0;
    //�����һ���ǿո���ĸ��ʼ���㣬ע���ַ�����ֻ��һ����ĸ��ʱ��������Ҫend���ڵ���0
    while (end >= 0 && s[end] != ' ')
    {
        ++count;
        --end;
    }
    return count;
}


vector<int> plusOne(vector<int>& digits) {
    int flag = 0;//��λ
    digits[digits.size() - 1] += 1;//ĩλ+1
    for (int i = digits.size() - 1; i >= 0; --i)
    {
        digits[i] += flag;//���Ͻ�λ
        //����ʮ����Ҫ���������λ
        if (digits[i] > 9)
        {
            flag = 1;//��λ
            digits[i] %= 10;
            //��i����0ʱ��Ҫ�����ֶ���ǰ+1
            if (i == 0)
                digits.insert(digits.begin(), 1);
        }
        else
            flag = 0;
    }
    return digits;
}


string addBinary(string a, string b) {
    int flag = 0;//��λ
    int end1 = a.size() - 1;//��ȡ���һλ
    int end2 = b.size() - 1;//��ȡ���һλ
    string tmp;
    //������������������������
    for (; end1 >= 0 || end2 >= 0;)
    {
        int num = 0;
        //������û�б�����
        if (end1 >= 0 && end2 >= 0)
            num = (a[end1] - '0') + (b[end2] - '0');
        //����һ������������
        else
            num = (end1 >= 0) ? (a[end1] - '0') : (b[end2] - '0');
        num += flag;//�ǵü��Ͻ�λ
        if (num > 1)
        {
            flag = 1;
            num %= 2;
        }
        else
            flag = 0;
        tmp.insert(0, 1, num + '0');
        //������Ĳ��ܼ�
        if (end1 >= 0)
            --end1;
        if (end2 >= 0)
            --end2;
    }
    //����ͷ�������Ҫ��λ�����
    if (flag == 1)
        tmp.insert(0, 1, '1');
    return tmp;
}


void merge(vector<int>& A, int m, vector<int>& B, int n) {
    //ȡ�ɣ��ȸ�ֵ��ֱ������
    // for(int i = 0; i < B.size(); ++i)
    //     A[m++] = (B[i]);
    // sort(A.begin(), A.end());
    //����ָ�뷨
    int endA = m - 1, endB = n - 1, end = m + n - 1;
    //�ĸ����ĸ��ź���
    while (endB >= 0 && endA >= 0)
    {
        if (B[endB] > A[endA])
        {
            A[end] = B[endB];
            --endB;
        }
        else
        {
            A[end] = A[endA];
            --endA;
        }
        --end;
    }
    //��B�л�������ʱֱ�ӷ��뼴��
    while (endB >= 0)
    {
        A[end] = B[endB];
        --endB;
        --end;
    }
}


int findString(vector<string>& words, string s) {
    /*//ֱ�ӱ�����ʱ�临�Ӷ�O(n)
    for(int i = 0; i < words.size(); ++i)
    {
        if(words[i] == s)
            return i;
    }
    return -1;*/
    int left = 0;
    int right = words.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int tmp = mid;//�洢�м�ֵ
        //��mid�ǿ��ַ�������С�ڵ���rightʱ��ֱ���ӹ�
        while (mid <= right && words[mid] == "")
        {
            ++mid;
        }
        //һ��������right��˵���Ͳ����ұ���
        if (mid > right)
        {
            right = tmp - 1;//��right��ֵ��mid�����ȥ
            continue;//������Ҫ������һ��ѭ���������������ִ������Ĵ����д�ˣ����ƻ�ȥ��
        }
        //�������ַ�
        if (words[mid] > s)
            right = mid - 1;
        else if (words[mid] < s)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}