// 51. N 皇后

// 困难

// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<string>> result;
    vector<string> row;
    vector<bool> l, dr, dl; // 列 右对角线 左对角线
    string generator(int n, int index)
    {
        string s = "";
        for (int i = 0; i < n; i++)
        {
            if (i != index)
                s.push_back('.');
            else
                s.push_back('Q');
        }
        return s;
    }
    void backTrack(int n, int i)
    {
        if (i == n)
        {
            result.push_back(row);
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (l[j] && dr[j - i + n - 1] && dl[i + j])
            {
                row.push_back(generator(n, j));
                l[j] = false;
                dr[j - i + n - 1] = false;
                dl[i + j] = false;
                backTrack(n, i + 1);
                l[j] = true;
                dr[j - i + n - 1] = true;
                dl[i + j] = true;
                row.pop_back();
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        l.assign(n, true);
        dr.assign(2 * n - 1, true);
        dl.assign(2 * n - 1, true);
        backTrack(n, 0);

        return result;
    }
};