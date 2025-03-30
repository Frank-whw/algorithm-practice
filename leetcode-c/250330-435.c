// 435. 无重叠区间
// 中等

// 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。
// 返回 需要移除区间的最小数量，使剩余区间互不重叠 。

// 注意 只在一点上接触的区间是 不重叠的。
// 例如 [1, 2] 和 [2, 3] 是不重叠的。

int cmp(const void *a, const void *b)
{
    int *pa = *(int **)a;
    int *pb = *(int **)b;
    if (pa[0] != pb[0])
    {
        return pa[0] - pb[0];
    }
    return pa[1] - pb[1];
}

int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    for (int i = 0; i < intervalsSize; i++)
    {
        printf("%d %d\n", intervals[i][0], intervals[i][1]);
    }

    int removeNum = 0;
    int right = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] < right)
        {
            removeNum += 1;
            right = fmin(right, intervals[i][1]);
        }
        else if (intervals[i][0] >= right)
        {
            right = intervals[i][1];
        }
    }
    return removeNum;
}

// 思路不是很明确
// 本题的局部最优是保证：右边界尽可能小
// 如果新区域的左边界比右边界小，说明重合，此时取2个区域的右边界小的那个作为right
// 如果....................大，说明没有重合

// 下面优化一下代码
int cmp(const void *a, const void *b)
{
    return *((int **)a)[0] - *((int **)b)[0];
}
int eraseOverlapIntervals(int **intervals, int intervalsSize, int *intervalsColSize)
{
    if (intervalsSize == 0)
    {
        return 0;
    }
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    // count: 重叠的区间数量
    int count = 0;
    // end: 区间分割点
    int end = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] < end)
        {
            // 说明有重合, end取2个区间中较小的右边界
            end = fmin(end, intervals[i][1]);
            count++;
        }
        else
        {
            // 没有重合，更新end
            end = intervals[i][1];
        }
    }
    return count;
}