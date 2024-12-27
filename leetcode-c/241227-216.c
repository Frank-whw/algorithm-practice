// 216 组合总和三
// 中等
// 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
// 只使用数字1到9
// 每个数字 最多使用一次
// 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

// 示例 1:
// 输入: k = 3, n = 7
// 输出: [[1,2,4]]
// 解释:
// 1 + 2 + 4 = 7
// 没有其他符合的组合了。

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int *path;
int pathTop;
int **ans;
int ansTop;
int capacity;
void backtracking(int k, int n, int index, int sum)
{
    if (sum > n)
        return;
    if (pathTop == k)
    {
        printf("%d", sum);
        if (sum == n)
        {
            int *temp = malloc(sizeof(int) * pathTop);
            for (int i = 0; i < pathTop; i++)
            {
                temp[i] = path[i];
            }
            ans[ansTop++] = temp;
            return;
        }
        return;
    }
    for (int j = index; j <= 9; j++)
    {
        // printf("%d  ", j);
        path[pathTop++] = j;
        backtracking(k, n, j + 1, sum + j);
        pathTop--;
    }
}
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes)
{
    path = malloc(sizeof(int) * k);
    capacity = 10000;
    ans = malloc(sizeof(int *) * capacity);
    pathTop = ansTop = 0;
    backtracking(k, n, 1, 0);
    *returnSize = ansTop;
    *returnColumnSizes = malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}