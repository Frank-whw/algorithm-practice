// 198. 打家劫舍
// 中等

// 你是一个专业的小偷，计划偷窃沿街的房屋。
// 每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，
// 计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        else if (n == 1)
        {
            return nums[0];
        }
        else if (n == 3)
            return max(nums[0] + nums[2], nums[1]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + nums[0];
        for (int i = 3; i < n; i++)
        {
            dp[i] = max(dp[i - 3], dp[i - 2]) + nums[i];
            cout << dp[i] << " ";
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};

// 上面代码不太直观，不简洁
// dp[i]：第i个屋子被盗 所对应的最高金额

// 换一种定义，dp[i]：前i个屋子 所对应的最高金额

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[1], nums[0]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};