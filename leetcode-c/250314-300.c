// 300. 最长递增子序列
// 中等

// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
// 例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

int lengthOfLIS(int *nums, int numsSize)
{
    // 定义dp[i]：前i位的子序列且以nums[i]结尾的最长子序列的长度
    int *dp = malloc(sizeof(int) * numsSize);
    // 初始化
    for(int i = 0; i < numsSize; i++){
        dp[i] = 1;
    }
    for (int i = 1; i < numsSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
    }
    int max = dp[0];
    for (int i = 0; i < numsSize; i++)
    {
        if (dp[i] > max)
        {
            max = dp[i];
        }
        printf("%d ", dp[i]);
    }
    return max;
}

// dp
// 时间复杂度：O(n^2)
// dp数组的定义看了一眼提示，后面的状态转移方程倒没有问题