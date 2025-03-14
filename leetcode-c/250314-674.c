// 674. 最长连续递增序列
// 简单

// 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

// 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，
// 如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
// 那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

int findLengthOfLCIS(int *nums, int numsSize)
{
    // dp[i]:前i个且以nums[i]结尾的连续递增子序列的最长长度
    int *dp = malloc(sizeof(int) * numsSize);
    int result = 1;
    dp[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        dp[i] = 1;
        if (nums[i] > nums[i - 1])
        {
            dp[i] = max(dp[i], dp[i - 1] + 1);
        }
        if (dp[i] > result)
        {
            result = dp[i];
        }
    }
    return result;
}

// dp
// 很简单