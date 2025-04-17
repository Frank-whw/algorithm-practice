// 2176. 统计数组中相等且可以被整除的数对
// 简单

// 提示
// 给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k ，
// 请你返回满足 0 <= i < j < n ，nums[i] == nums[j]
// 且 (i * j) 能被 k 整除的数对 (i, j) 的 数目 。
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int count = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                {
                    count++;
                }
            }
             }
        return count;
    }
};


// 直接暴力