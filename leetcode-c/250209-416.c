// 416. 分割等和子集
// 中等

// 给你一个 只包含正整数 的 非空 数组 nums 。
// 请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
#include<stdbool.h>

bool canPartition(int* nums, int numsSize) {
    int weight = 0;
    for(int i = 0; i < numsSize; i++){
        weight += nums[i];
    }
    if(weight % 2 != 0){
        // 不是2的倍数
        return false;
    }
    weight = weight / 2;
    int* dp = malloc(sizeof(int) * (weight + 1));
    for(int i = 0; i <= weight; i++){
        dp[i] = 0;
    }
    for(int i = 0; i < numsSize; i++){
        for(int j = weight; j >= nums[i]; j--){
            dp[j] = fmax(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    // 集合中的元素正好可以凑成总和target
    if (dp[weight] == weight) return true;
    return false;
}

// dp
// 转换为01背包题
// 01背包相对于本题，主要要理解，题目中物品是nums[i]，
// 重量是nums[i]，价值也是nums[i]，背包体积是sum/2。