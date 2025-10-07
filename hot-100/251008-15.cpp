// 15. 三数之和

// 中等

// 提示
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
// 满足 i != j、i != k 且 j != k ，
// 同时还满足 nums[i] + nums[j] + nums[k] == 0 。
// 请你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>> res;
        // sort(nums.begin(), nums.end());
        // for(int left = 0; left < nums.size() - 2; left++){
        //     for(int mid = left + 1; mid < nums.size() - 1; mid++){
        //         int right = nums.size() - 1;
        //         while(nums[right] + nums[left] + nums[mid] > 0 && mid < right){
        //             right--;
        //         }
        //         if(nums[right] + nums[left] + nums[mid] == 0){
        //             res.push_back({nums[left],nums[mid], nums[right]});
        //         }
        //     }
        // }    
        // return res;

        // 没有考虑去重的情况
        // 另外发现当 left 和 mid 右移的时候，对应的值相加是变大的，所以right不用重置到最右侧
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int left = 0; left < nums.size() - 2; left++){
            // ！！！
            if(left > 0 && nums[left] == nums[left - 1])    continue;
            int right = nums.size() - 1;

            for(int mid = left + 1; mid < nums.size() - 1; mid++){
                // ！！！
                if(mid > left + 1 && nums[mid] == nums[mid - 1])   continue;
                while(nums[right] + nums[left] + nums[mid] > 0 && mid < right){
                    right--;
                }
                if(mid == right)    break; // !!!
                if(nums[right] + nums[left] + nums[mid] == 0){
                    res.push_back({nums[left],nums[mid], nums[right]});
                }
            }
        }    
        return res;
    }
};


// 核心想法是 排序 + 双指针 + 去重
// 去重：每一层循环 跳过重复元素
// 典型的双指针解法：

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = -nums[i];
            if(target < 0)  break;
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1])  l++;
                    while(l < r && nums[r] == nums[r + 1])  r--;
                }else if(sum > target) r--;
                else l++;
            }
        }
        return ans;
    }
};