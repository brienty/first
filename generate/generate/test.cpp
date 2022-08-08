#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    //创建vv
    vector<vector<int>> vv;
    //初始化前numRows行
    vv.resize(numRows);
    //初始化每行中的int数据为0
    for (size_t i = 0; i < vv.size(); ++i) {
        //首尾赋值为1，其他为0
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