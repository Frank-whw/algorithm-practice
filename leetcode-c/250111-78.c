// 78. 子集
// 中等

// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **result;
int *path;
int pathTop;
int resultTop;
int *resultSize;

void copy()
{
    int *temp = malloc(sizeof(int) * pathTop);
    for (int i = 0; i < pathTop; i++)
    {
        temp[i] = path[i];
    }
    resultSize[resultTop] = pathTop;
    result[resultTop++] = temp;
}
void backtracking(int *nums, int numsSize, int startIndex)
{
    // if (startIndex == numsSize)
    // {
    //     copy();
    //     return;
    // }

    for (int i = startIndex; i < numsSize; i++)
    {
        path[pathTop++] = nums[i];
        copy();
        backtracking(nums, numsSize, i + 1);
        pathTop -= 1;
    }
}
int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    result = malloc(sizeof(int *) * 10000);
    path = malloc(sizeof(int) * numsSize);
    resultSize = malloc(sizeof(int) * 10000);
    pathTop = 0;
    resultTop = 1;
    resultSize[0] = 0;

    backtracking(nums, numsSize, 0);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int *) * resultTop);
    for (int i = 0; i < resultTop; i++)
    {
        (*returnColumnSizes)[i] = resultSize[i];
    }
    return result;
}

// 回溯基本题
// 难点在于copy()的位置
// 这题copy的时机不是 startIndex==numsSize的时候，而是每次更新path数组的时候