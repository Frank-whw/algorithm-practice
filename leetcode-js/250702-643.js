// 643. 子数组最大平均数 I

// 给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。

// 请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。

// 任何误差小于 10-5 的答案都将被视为正确答案。

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function(nums, k) {
    let sum = 0;
    for(let i = 0; i < k; i++){
        sum += nums[i];
    }
    let result = sum;
    for(let left = 0; left + k < nums.length; left++){
        sum -= nums[left];
        sum += nums[left + k];
        result = Math.max(result, sum);
    }
    return result / k;
};