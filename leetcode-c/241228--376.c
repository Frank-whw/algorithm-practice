// 376. 摆动序列
// 中等
// 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
// 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
// 相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
// 子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
// 给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。

int wiggleMaxLength(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return 1;
    int length = 1;
    int preDiff = 0, curDiff = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        // 当前的差值
        curDiff = nums[i + 1] - nums[i];

        // 若preDiff与curDiff符号不符，则子序列长度+1。更新preDiff的符号
        // 若preDiff与curDiff符号一致，当前i元素为连续升序/连续降序子序列的中间元素。不被记录入长度
        // 注：当preDiff为0时，curDiff为正或为负都属于符号不同
        if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0))
        {
            preDiff = curDiff;
            length++;
        }
    }

    return length;
}

// 贪心
// 贪心的思想：局部最优推出全局最优
// 局部最优：删除单调坡度上的节点
// 全局最优：有最多的局部峰值