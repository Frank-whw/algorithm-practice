// 2369. 检查数组是否存在有效划分
// 题目难度Medium
// 给你一个下标从 0 开始的整数数组 nums ，你必须将数组划分为一个或多个 连续 子数组。

// 如果获得的这些子数组中每个都能满足下述条件 之一 ，则可以称其为数组的一种 有效 划分：
// 子数组 恰 由 2 个相等元素组成，例如，子数组 [2,2] 。
// 子数组 恰 由 3 个相等元素组成，例如，子数组 [4,4,4] 。
// 子数组 恰 由 3 个连续递增元素组成，并且相邻元素之间的差值为 1 。例如，子数组 [3,4,5] ，但是子数组 [1,3,5] 不符合要求。
// 如果数组 至少 存在一种有效划分，返回 true ，否则，返回 false 。

#include <stdbool.h>
bool validPartition(int *nums, int numsSize)
{
    if (numsSize < 2)
        return false;
    bool *dp = malloc(sizeof(bool) * (numsSize + 1));
    for (int i = 0; i <= numsSize; i++)
    {
        dp[i] = false;
    }
    dp[0] = true;
    for (int i = 2; i <= numsSize; i++)
    {
        // 情况一：2 个相等元素
        if (nums[i - 1] == nums[i - 2])
        {
            dp[i] = dp[i] || dp[i - 2];
        }
        if (i >= 3)
        {
            // 情况二：3个相等元素
            if (nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3])
            {
                dp[i] = dp[i] || dp[i - 3];
            }
            // 情况三：3个连续递增元素
            if (nums[i - 1] - nums[i - 2] == 1 && nums[i - 2] - nums[i - 3] == 1)
            {
                dp[i] = dp[i] || dp[i - 3];
            }
        }
        return dp[numsSize];
    }
}