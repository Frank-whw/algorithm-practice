// 2537. 统计好子数组的数目
// 中等

// 提示
// 给你一个整数数组 nums 和一个整数 k ，请你返回 nums 中 好 子数组的数目。

// 一个子数组 arr 如果有 至少 k 对下标 (i, j) 满足 i < j 且 arr[i] == arr[j] ，那么称它是一个 好 子数组。

// 子数组 是原数组中一段连续 非空 的元素序列。

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    long long countGood(vector<int> &nums, int k)
    {
        unordered_map<int, int> count_map;
        int left = 0, right = 0;
        int count = 0, n = nums.size();
        long long result = 0;
        while (right < n)
        {
            int key = nums[right];
            count += count_map[key];
            count_map[key]++;
            while (count >= k)
            {
                result += n - right;
                int left_key = nums[left];
                count_map[left_key]--;
                count -= count_map[left_key];
                left++;
            }
            right += 1;
        }
        return result;
    }
};

// 连续子数组->滑动窗口问题
// 用left,right分别记录窗口的左右边界
// 用哈希表记录数字出现的次数