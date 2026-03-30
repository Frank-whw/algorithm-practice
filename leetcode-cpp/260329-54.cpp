#include<bits/stdc++.h>
using namespace std;

// 法一：通过d例举4种方向，控制i j模拟矩阵的运行线路
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        vector<int> result;
        int i = 0, j = 0, count = 0, index = 0;
        int d[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        while (count < n * m)
        {
            result.push_back(matrix[i][j]);
            isVisited[i][j] = true;
            int nx = i + d[index][0], ny = j + d[index][1];
            if(nx >= n || ny >= m || nx < 0 ||ny < 0 || isVisited[nx][ny]){
                index = (index + 1) % 4;
                nx = i + d[index][0], ny = j + d[index][1];
            }
            i = nx, j = ny;
        }
        return result;
        
    }
};

// 法二 一层一层剥离
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, left = 0, bottom = n - 1, right = m - 1;
        vector<int> result;
        while(top <= bottom && left <= right){
            for(int j = left; j <= right; j++){
                result.push_back(matrix[top][j]);
            }
            top++;
            for (int i = top; i <= bottom; i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){
                for (int j = right; j >= left; j--)
                {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            
            
        }
        return result;
    }
};