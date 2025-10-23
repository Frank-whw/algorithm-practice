// 48. 旋转图像

// 中等

// 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

// 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void swap(int *a, int *b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = i; j < matrix[0].size(); j++)
            {
                swap(&matrix[i][j], &matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

// 垂直镜像 + 转置
// 第一时间有点难想到