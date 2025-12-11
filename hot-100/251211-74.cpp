// 74. 搜索二维矩阵

// 中等

// 给你一个满足下述两条属性的 m x n 整数矩阵：

// 每行中的整数从左到右按非严格递增顺序排列。
// 每行的第一个整数大于前一行的最后一个整数。
// 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int x = mid / n, y = mid % n;
            int num = matrix[x][y];
            if(num == target)   return true;
            else if(num < target)   left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

// 把二维矩阵扁平化
// 用一维二分