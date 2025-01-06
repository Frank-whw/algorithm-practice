// 55. 跳跃游戏
// 中等

// 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

// 示例 1：
// 输入：nums = [2,3,1,1,4]
// 输出：true
// 解释：可以先跳 1 步，从下标 0 到达下标 1, 
// 然后再从下标 1 跳 3 步到达最后一个下标。

bool canJump(int* nums, int numsSize) {
    int far = 0;
    for(int i = 0; i < numsSize - 1; i++){
        if(i <= far){
            printf("i:%d far:%d\n", i, far);
            far = fmax(far, nums[i]+i);
        }
    }
    return numsSize - 1 > far ? false : true;
}

// emmm用的是自己想的方法，秒了，但是复杂度太高
// 看了代码随想录 才知道这就是贪心算法
// 局部最优->可覆盖的最远范围