// 1005. K 次取反后最大化的数组和
// 简单

// 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

// 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
// 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
// 以这种方式修改数组后，返回数组 可能的最大和 。

int minNum(int* nums, int numsSize){
    int min = nums[0];
    int index = 0;
    for(int i = 1; i < numsSize; i++){
        if(nums[i] < min){
            min = nums[i];
            index = i;
        }
    }
    return index;
}
int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    for(int i = 0; i < k; i++){
        int index = minNum(nums, numsSize);
        nums[index] *= -1;
    }
    int sum = 0;
    for(int i = 0; i < numsSize;i++){
        sum += nums[i];
    }
    return sum;
}   

// 贪心
// 局部最优：每一次调换 调换最小的值
// 通过minNUm函数，返回最小值的下标