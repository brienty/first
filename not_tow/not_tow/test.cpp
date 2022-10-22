#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row = 0, list = 0;
    while (cin >> row >> list) {
        //初始化
        int count = 0;
        vector<vector<int>> vv;
        vv.resize(row);
        for (auto& e : vv) {
            e.resize(list);
        }
        for (int i = 0; i < vv.size(); ++i) {
            for (int j = 0; j < vv[i].size(); ++j) {
                //当vv的值是0时++count
                if (vv[i][j] == 0) {
                    ++count;
                    //从0,0开始+2的一定不能要，而对角线的在vv==0时就已经判断完
                    if (i + 2 < row)
                        vv[i + 2][j] = -1;
                    if (j + 2 < list)
                        vv[i][j + 2] = -1;
                }
            }
        }
        cout << count;
    }
}