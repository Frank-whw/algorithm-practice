// 78. 子集

// 中等

// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTrack(vector<int>& nums, int start){
        result.push_back(path);
        for(int i = start + 1; i < nums.size(); i++){
            path.push_back(nums[i]);
            backTrack(nums, i);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back(path);
        for(int i = 0; i < nums.size(); i++){
            path.push_back(nums[i]);
            backTrack(nums, i);
            path.pop_back();
        }
        return result;
    }
};