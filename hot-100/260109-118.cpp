// 118. 杨辉三角
// 简单

// 给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> tmp(i + 1, 0);
            tmp[0] = 1;
            tmp[i] = 1;
            for (int j = 1; j < i; j++)
            {
                tmp[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(tmp);
        }
        return result;
    }
};