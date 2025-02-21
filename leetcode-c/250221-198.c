// 198. 打家劫舍
// 中等

// 你是一个专业的小偷，计划偷窃沿街的房屋。
// 每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，
// 计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

int rob(int *nums, int numsSize)
{
    if(numsSize == 1)   return nums[0];
    // dp[i]: i号房屋被偷时 的最高金额
    int *dp = malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];

    for (int i = 1; i < numsSize; i++)
    {
        if (i == 1)
            dp[i] = nums[1];
        else if (i == 2)
            dp[i] = nums[0] + nums[2];
        else
        {
            dp[i] = fmax(dp[i - 3], dp[i - 2]) + nums[i];
        }
    }

    // print
    for (int i = 0; i < numsSize; i++)
    {
        printf("%d ", dp[i]);
    }
    return fmax(dp[numsSize - 1], dp[numsSize - 2]);
}
//当前状态和前面状态会有一种依赖关系，那么这种依赖关系都是动规的递推公式。

// 这边与代码随想录给的解法不同
// dp[i]表示i号房屋被偷的最大情况
// 那么dp[0] = nums[0],dp[1] = nums[1],dp[2] = nums[0] + nums[2]
// 递推关系：dp[i] = fmax(dp[i - 1], dp[i - 3]) + nums[i]
// 最后返回fmax(dp[numsSize - 1], dp[numsSize - 2])