// 416. 分割等和子集

// 中等

// 给你一个 只包含正整数 的 非空 数组 nums 。
// 请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // dp[i][j]表示在[0,i]中的所有整数，能否选出一些数 使得这些数之和恰好为整数j
        int n = nums.size();
        if (n < 2)
            return false;
        int sum = 0, maxNum = 0;
        for (int num : nums)
        {
            sum += num;
            maxNum = max(num, maxNum);
        }
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        if (maxNum > target)
            return false;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = 1; j <= target; j++)
            {
                if (j >= num)
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};