// 34. 在排序数组中查找元素的第一个和最后一个位置

// 中等

// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
// 请你找出给定目标值在数组中的开始位置和结束位置。

// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // 返回 nums 中最小满足 nums[i] >= target 的i
    int low_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target)
            {
                r = mid - 1;
            }else{
                l = mid + 1;
            }
            
        }
        return l;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = low_bound(nums, target), r = low_bound(nums, target + 1) - 1;
        if(l > r)   return {-1, -1};
        else return {l, r};
    }
};

// 第一想法是 分别找到nums中第一个 target，最后一个 target，但是2个逻辑不通用
// 这个想法秒在用 low_bound 统一成「找下界」这一个通用逻辑，避免写两套相似的二分代码