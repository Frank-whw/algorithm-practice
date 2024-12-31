// 53. 最大子数组和
// 中等

// 给你一个整数数组 nums ，请你找出一个具有最大和
// 的连续子数组（子数组最少包含一个元素），返回其最大和。
// 子数组
// 是数组中的一个连续部分。
// 示例 1：
// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

int maxSubArray(int *nums, int numsSize)
{
    int count = 0, start = 0, result = INT_MIN;
    while (start < numsSize)
    {
        // if (count + nums[start] < 0)
        // {
        //     //printf("%d ", nums[start]);
        //     start += 1;
        //     count = 0;
        // }
        // else
        // {
        //     count += nums[start];
        //     start += 1;
        //     if (count > result)
        //     {
        //         result = count;
        //     }
        // }

        count += nums[start];
        result = count > result ? count : result;
        count = count < 0 ? 0 : count;
        start += 1;
    }
    return result;
}

// 贪心
// 局部最优->全局最优
// 本题的全局最优在于 当count+nums[start]<0时，说明nums[start]是个累赘
// 所以更新count=0，从start+1重新计算
// 被注释的代码是自己第一次写的，有思路但是不清晰，还得练