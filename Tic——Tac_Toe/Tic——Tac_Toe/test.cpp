#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

bool checkWon(vector<vector<int> > board) {
    //处理每行是否是1
    int count = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == 1)
            {
                ++count;
            }
            else
            {
                count = 0;
                break;
            }
        }
    }
    if (count == 3)
        return true;
    //处理每列是否是1
    count = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[j][i] == 1)
                ++count;
            else
            {
                count = 0;
                break;
            }
        }
        if (count == 3)
            return true;
    }
    //处理对角线
    count = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][i] == 1)
            ++count;
    }
    if (count == 3)
        return true;
    return false;
}

int main()
{
    vector<vector<int>> board;
    board.resize(3);
    for (auto& e : board)
    {
        e.resize(3);
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> board[i][j];
        }
    }
    cout << checkWon(board);
    return 0;
}