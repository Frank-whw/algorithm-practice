#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从右上角开始遍历 看出一颗二叉搜索树
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = m - 1;
        while(x < n && y >= 0){
            if(target > matrix[x][y]){
                x++;
            }else if(target < matrix[x][y]){
                y--;
            }else{
                return true;
            }
        }
        return false;
    }
};