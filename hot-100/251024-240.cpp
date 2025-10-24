// 240. 搜索二维矩阵 II

// 中等

// 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

// 每行的元素从左到右升序排列。
// 每列的元素从上到下升序排列。
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        // 从右上角开始搜索
        int row = 0, col = n - 1;
        while (row < m && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {
                // 当前元素太大，左移一列
                col--;
            }
            else
            {
                // 当前元素太小，下移一行
                row++;
            }
        }
        // 越界则不存在
        return false;
    }
};