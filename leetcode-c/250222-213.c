// 213. 打家劫舍 II
// 中等

// 提示
// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
// 这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
// 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

// 给定一个代表每个房屋存放金额的非负整数数组，
// 计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

int rob1(int* nums, int numsSize){
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
    return fmax(dp[numsSize - 1], dp[numsSize - 2]);
}
int rob(int* nums, int numsSize) {
    if(numsSize == 0)   return 0;
    if(numsSize == 1)   return nums[0];
    int result1 = rob1(nums, numsSize - 1);
    int* nums2 = malloc(sizeof(int) * (numsSize - 1));
    for(int i = 1; i < numsSize; i ++){
        nums2[i - 1] = nums[i];
    }
    int result2 = rob1(nums2, numsSize - 1);
    return fmax(result1, result2);
}

// 把环形分为3中情况
// 情况1：不考虑首尾
// 情况2：不考虑首
// 情况3：不考虑尾
// 分析得：case2&3都包括了3
// 所以将环形问题拆解成了2个线性问题
// 而线性问题可以用题198中的rob函数（在本题封装成了rob1函数）
// 将前numsSize-1个元素和后numsSize-1个元素分别传入rob1
// 得到的result取最大值