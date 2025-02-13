// 494. 目标和
// 中等

// 给你一个非负整数数组 nums 和一个整数 target 。

// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

int findTargetSumWays(int *nums, int numsSize, int target)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }

    if(abs(target) > sum){
        return 0;
    }
    // dp[i][j]表示前i个数字 组成i-sum的情况个数
    int **dp = malloc(sizeof(int *) * (numsSize + 1));
    for (int i = 0; i <= numsSize; i++)
    {
        dp[i] = malloc(sizeof(int) * (2 * sum + 1));
    }

    // 初始化i=0
    for (int j = 0; j <= 2 * sum; j++)
    {
        dp[0][j] = 0;
    }
    dp[0][sum] = 1;

    // 遍历
    for (int i = 1; i <= numsSize; i++)
    {
        for (int j = -1 * sum; j <= sum; j++)
        {
            dp[i][j + sum] = 0;
            // nums[i]前是+号
            if (j - nums[i - 1] + sum >= 0)
            {
                dp[i][j + sum] += dp[i - 1][j - nums[i - 1] + sum];
            }
            // nums[i]前是-号
            if (j + nums[i - 1] <= sum)
            {
                dp[i][j + sum] += dp[i - 1][j + nums[i - 1] + sum];
            }
        }
    }

    return dp[numsSize][target + sum];
}

// dp
// dp[i][j]定义：前i个数组成j-sum的情况个数，i从0到numsSize
// 状态转移方程：dp[i][j + sum] = dp[i - 1][j - nums[i - 1] + sum] + dp[i - 1][j + nums[i - 1] + sum]
// 注意：在遍历外层循环时，i从i到numsSize，所以nums的遍历是i-1.从0到numsSize-1
