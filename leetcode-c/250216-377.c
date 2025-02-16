// 377. 组合总和 Ⅳ
// 中等

// 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
// 请你从 nums 中找出并返回总和为 target 的元素组合的个数。
// 题目数据保证答案符合 32 位整数范围。

int combinationSum4(int *nums, int numsSize, int target)
{
    // 使用一维dp数组，dp[j]表示和为j的排列数
    unsigned int *dp = (unsigned int*)calloc(target + 1, sizeof(unsigned int));
    dp[0] = 1; // 初始化：和为0有1种方案（空集）

    // 外层遍历容量j，内层遍历所有物品（保证排列顺序自由）
    for (int j = 1; j <= target; j++) {
        for (int i = 0; i < numsSize; i++) {
            if (j >= nums[i]) {
                dp[j] += dp[j - nums[i]]; // 累加所有可能的子问题解
            }
        }
    }
    int result = dp[target];
    free(dp);
    return result;
}


// 完全背包
// 排列问题
// 完全背包的排列问题应当使用一维数组，因为每个位置的状态需动态更新所有可能的物品组合。
// 排列问题需要外层遍历容量j，内层遍历所有物品nums。
// 排列问题需要累加所有可能的子问题解（dp[j] += dp[j - num]） 完全背包的核心是允许重复选择