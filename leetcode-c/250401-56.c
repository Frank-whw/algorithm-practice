// 56. 合并区间
// 中等

// 以数组 intervals 表示若干个区间的集合，
// 其中单个区间为 intervals[i] = [starti, endi] 。
// 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该
// 数组需恰好覆盖输入中的所有区间 。

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b)
{
    return *((int **)a)[0] - *((int **)b)[0];
}
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
    int **result = malloc(sizeof(int *) * intervalsSize);
    int resultTop = 0;
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    int left = intervals[0][0], right = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++)
    {
        if (intervals[i][0] <= right)
        {
            // 重叠
            right = fmax(right, intervals[i][1]);
        }
        else
        {
            // 没有重叠
            result[resultTop] = malloc(sizeof(int) * 2);
            result[resultTop][0] = left;
            result[resultTop][1] = right;
            left = intervals[i][0];
            right = intervals[i][1];
            resultTop += 1;
        }
    }
    // 添加最后一个区间
    result[resultTop] = malloc(sizeof(int) * 2);
    result[resultTop][0] = left;
    result[resultTop][1] = right;
    resultTop++;

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int) * resultTop);
    for (int i = 0; i < resultTop; i++)
    {
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}

// 思路很简单
// 先把所有的区间按照左边界进行排序
// 此时只需要考虑下一个区间的左边界和上一个区间的右边界就可以判断是否重叠

// 注意returnColumnSizes的意义，一开始写的时候有些不知所措
// 这是一个指向一维数组的指针