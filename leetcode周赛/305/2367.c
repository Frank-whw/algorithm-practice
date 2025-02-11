// 2367. 等差三元组的数目
// 题目难度Easy
// 给你一个下标从 0 开始、严格递增 的整数数组 nums 和一个正整数 diff 。
// 如果满足下述全部条件，则三元组 (i, j, k) 就是一个 等差三元组 ：

// i < j < k ，
// nums[j] - nums[i] == diff 且
// nums[k] - nums[j] == diff
// 返回不同 等差三元组 的数目。

int isIn(int *nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == target)
        {
            return 1;
        }
    }
    return 0;
}

int arithmeticTriplets(int *nums, int numsSize, int diff)
{
    int count = 0;
    for (int i = 0; i < numsSize - 2; i++)
    {
        if (isIn(nums, numsSize, nums[i] + diff) && isIn(nums, numsSize, nums[i] + diff + diff))
        {
            count += 1;
        }
    }
    return count;
}