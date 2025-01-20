// 90. 子集 II
// 中等

// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的
// 子集（幂集）。
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdlib.h>

int **result;
int *resultSize;
int resultTop;
int *path;
int pathTop;
int* used;

int cmp(const void* a, const void* b){
    return (*(int *)a - *(int *)b);
}

void copy()
{
    int *temp = malloc(sizeof(int) * pathTop);
    for (int i = 0; i < pathTop; i++)
    {
        temp[i] = path[i];
    }
    resultSize[resultTop] = pathTop;
    result[resultTop++] = temp;
    return;
}

void backTracking(int *nums, int numsSize, int startIndex)
{
    copy();

    for(int i = startIndex; i < numsSize; i++){
        if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0){
            continue;
        }
        path[pathTop++] = nums[i];
        used[i] = 1;
        backTracking(nums, numsSize, i + 1);
        used[i] = 0;
        pathTop -= 1;
    }
    return;
}
int **subsetsWithDup(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    result = malloc(sizeof(int *) * 1000);
    resultSize = malloc(sizeof(int) * 1000);
    used = malloc(sizeof(int) * numsSize);
    path = malloc(sizeof(int) * numsSize);
    pathTop = 0; 
    resultTop = 0;
    // resultSize[0] = 0;
    qsort(nums,numsSize, sizeof(int), cmp);
    backTracking(nums, numsSize, 0);
    
    *returnSize = resultTop;

    *returnColumnSizes = malloc(sizeof(int *) * resultTop);
    for (int i = 0; i < resultTop; i++)
    {
        (*returnColumnSizes)[i] = resultSize[i];
    }
    return result;

}


// 回溯题
// 难点在于如何 去重
// 本题是树层去重，去重前需要进行 排序
// 排序通过qsort+自定义cmp，其中cmp的代码need review
