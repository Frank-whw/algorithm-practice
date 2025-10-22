// 54. 螺旋矩阵

// 中等

// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int direction[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<int> ans;
        int x = 0, y = 0, d = 0;
        for (int i = 0; i < n * m; i++)
        {
            ans.push_back(matrix[x][y]);
            visited[x][y] = 1;
            int x_next = x + direction[d][0], y_next = y + direction[d][1];
            if (x_next == m || y_next == n || x_next == -1 || y_next == -1 || visited[x_next][y_next])
            {
                d = (d + 1) % 4;
                x_next = x + direction[d][0], y_next = y + direction[d][1];
            }
            x = x_next, y = y_next;

            cout << d << " " << x << " & " << y << endl;
        }
        return ans;
    }
};

// 空间复杂度：O(mn)
// 时间复杂度：O(mn)

// 方法二
// 按层模拟
// 1. 从左到右遍历上侧元素，依次为 (top,left) 到 (top,right)。

// 2. 从上到下遍历右侧元素，依次为 (top+1,right) 到 (bottom,right)。

// 3. 如果 left<right 且 top<bottom，则从右到左遍历下侧元素，
//    依次为 (bottom,right−1) 到 (bottom,left+1)，以及从下到上遍历左侧元素，
//    依次为 (bottom,left) 到 (top+1,left)。
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};