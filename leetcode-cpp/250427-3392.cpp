// 3392. 统计符合条件长度为 3 的子数组数目
// 简单

// 提示
// 给你一个整数数组 nums ，请你返回长度为 3 的 子数组 的数量，
// 满足第一个数和第三个数的和恰好为第二个数的一半。

// 子数组 指的是一个数组中连续 非空 的元素序列。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        // 滑动窗口
        int l = 0, r = 2, n = nums.size();
        int result = 0;
        while (r < n)
        {
            if (nums[l] + nums[r] == 0.5 * nums[(l + r) / 2])
            {
                result += 1;
            }
            r++;
            l++;
        }
        return result;
    }
};