// 53. 最大子数组和

// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
// 返回其最大和。

// 子数组是数组中的一个连续部分。

int maxSubArray(int *nums, int numsSize)
{
    // dp[i]: 以i结尾的有最大和的连续子数组
    int *dp = malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    int result = dp[0];
    for (int i = 1; i < numsSize; i++)
    {
        dp[i] = fmax(dp[i - 1] + nums[i], nums[i]);
        if (dp[i] > result)
        {
            result = dp[i];
        }
    }
    return result;
}

// dp版的最大子数组
// 还是很简单的