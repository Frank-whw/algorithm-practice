// 1. 两数之和
// 简单

// 提示
// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

// 你可以按任意顺序返回答案。

#include<bits/stdc++.h>
// 暴力穷举
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // key:数组元素值，value:该元素的索引
        unordered_map<int,int> hashtable;
        for(int i = 0; i < nums.size(); i++){
            auto item = hashtable.find(target - nums[i]);
            if(item != hashtable.end()){
                // item->second:harshtable中存储的该元素的索引
                return {item->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};