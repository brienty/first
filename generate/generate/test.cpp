#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    //����vv
    vector<vector<int>> vv;
    //��ʼ��ǰnumRows��
    vv.resize(numRows);
    //��ʼ��ÿ���е�int����Ϊ0
    for (size_t i = 0; i < vv.size(); ++i) {
        //��β��ֵΪ1������Ϊ0
        vv[i].resize(i + 1, 0);
        vv[i][0] = vv[i][vv[i].size() - 1] = 1;
    }
    for (size_t i = 0; i < vv.size(); ++i) {
        for (size_t j = 0; j < vv[i].size(); ++j) {
            if (vv[i][j] == 0) {
                vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
            }
        }
    }
    return vv;
}

int main()
{
    generate(5);
	return 0;
}