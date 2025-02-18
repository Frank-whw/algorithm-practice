// 377. 组合总和 Ⅳ
// 中等

// 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
// 请你从 nums 中找出并返回总和为 target 的元素组合的个数。
// 题目数据保证答案符合 32 位整数范围。

int combinationSum4(int* nums, int numsSize, int target) {
    // dp[i]: 总和为i组合个数
    // 使用一维dp数组，dp[j]表示和为j的排列数
    unsigned int *dp = (unsigned int*)calloc(target + 1, sizeof(unsigned int));
    dp[0] = 1; // 初始化：和为0有1种方案（空集）
    for(int i = 1; i<=target; i++){
        for(int j = 0; j < numsSize; j++){
            if(i >= nums[j]){
                dp[i] += dp[i - nums[j]];
            }
        }
    }

    return dp[target];
}