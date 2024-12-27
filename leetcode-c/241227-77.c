// 77.组合
// 中等
// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
// 任何顺序
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int **ans; // use to store answer
int *path;
int pathTop;
int ansTop;
int capacity;

void backtracking(int n, int k, int index)
{
    if (pathTop == k)
    {
        // path数组为我们动态申请，若直接将其地址放入二维数组，path数组中的值会随着我们回溯而逐渐变化
        // 因此创建新的数组存储path中的值
        int *temp = malloc(sizeof(int) * k);
        for (int i = 0; i < k; i++)
        {
            temp[i] = path[i];
        }
        // 动态扩容 ans
        if (ansTop >= capacity)
        {
            capacity *= 2;
            ans = realloc(ans, sizeof(int *) * capacity);
            if (ans == NULL)
            {
                perror("realloc failed");
                exit(EXIT_FAILURE);
            }
        }
        ans[ansTop++] = temp;
        return;
    }
    for (int j = index; j <= n - (k - pathTop) + 1; j++)
    {
        path[pathTop++] = j;
        backtracking(n, k, j + 1);
        pathTop--;
    }
}
int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    // path 用来存储符合条件的结果
    path = malloc(sizeof(int) * k);
    capacity = 10000;
    // ans 存储path的集合
    ans = malloc(sizeof(int *) * capacity);
    pathTop = ansTop = 0;
    // backtracking
    backtracking(n, k, 1);
    *returnSize = ansTop; // ans数组的大小
    *returnColumnSizes = malloc(sizeof(int) * ansTop);
    for (int i = 0; i < ansTop; i++)
    {
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}

// 回溯算法
// 用path记录当前符合要求的数组，如果这个path的大小 == k，则放进用来存储数组集的ans数组
// 注意：不能直接put path into ans，因为后续回溯中path的内容会改变，所以需要temp复制path的内容，put temp into ans
// 对于n，k较大的情况，初始的capacity = 10000会溢出，所以需要加上动态扩容