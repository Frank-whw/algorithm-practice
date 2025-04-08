// 3507. 移除最小数对使数组有序 I
// 给你一个数组 nums，你可以执行以下操作任意次数：

// 选择 相邻 元素对中 和最小 的一对。如果存在多个这样的对，选择最左边的一个。
// 用它们的和替换这对元素。
// 返回将数组变为 非递减 所需的 最小操作次数 。

// 如果一个数组中每个元素都大于或等于它前一个元素（如果存在的话），则称该数组为非递减


// 检查数组是否为非递减
int isNonDecreasing(int *nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            return 0;
        }
    }
    return 1;
}
int minimumPairRemoval(int *nums, int numsSize)
{
    if (isNonDecreasing(nums, numsSize)) {
        return 0;
    }
    int pairSum = __INT_MAX__;
    int indexToPair = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] + nums[i + 1] < pairSum)
        {
            // printf("us");
            indexToPair = i;
            pairSum = nums[i] + nums[i + 1];
        }
    }
    nums[indexToPair] += nums[indexToPair + 1];
    // printf("%d\n", indexToPair);
    for (int i = indexToPair + 1; i < numsSize - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
    return 1 + minimumPairRemoval(nums, numsSize - 1);
}