// 46. 全排列

// 中等

// 给定一个不含重复数字的数组 nums ，
// 返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTrack(vector<int>& nums, vector<bool> visited){
        bool isFull = true;
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                isFull = false;
                visited[i] = true;
                path.push_back(nums[i]);
                backTrack(nums, visited);
                visited[i] = false;
                path.pop_back();
            }
        }
        if(isFull){
            result.push_back(path);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            visited[i] = true;
            path.push_back(nums[i]);
            backTrack(nums, visited);
            visited[i] = false;
            path.pop_back();
        }
        return result;
    }
};

// 回溯
// 没想到几个月没写 竟还能一步到位