// 40. 组合总和 II
// 中等

// 给定一个候选人编号的集合 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用 一次 。
// 注意：解集不能包含重复的组合。

// 示例 1:
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 输出:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

int *path;
int pathTop;
int resultTop;
int **result;
// 用来记录result中每一个path的大小
int *length;
void backtracking(int *candidates, int candidatesSize, int target, int start, int sum)
{
    if (sum > target)
    {
        return;
    }
    if (sum == target)
    {
        int *temp = malloc(sizeof(int) * pathTop);
        for (int i = 0; i < pathTop; i++)
        {
            temp[i] = path[i];
            printf("%d ", temp[i]);
        }
        length[resultTop] = pathTop;
        result[resultTop++] = temp;
        return;
    }
    for (int i = start; i < candidatesSize; i++)
    {
        // important
        if (i > start && candidates[i] == candidates[i - 1])
            continue;
        path[pathTop++] = candidates[i];
        // printf("%d ", path[pathTop -1 ]);
        backtracking(candidates, candidatesSize, target, i + 1, sum + candidates[i]);
        pathTop--;
    }
    // printf("\n");
}
int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    path = malloc(sizeof(int) * candidatesSize);
    result = malloc(sizeof(int *) * 1000);
    pathTop = resultTop = 0;
    length = malloc(sizeof(int) * 1000);
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    backtracking(candidates, candidatesSize, target, 0, 0);
    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int) * resultTop);
    for (int i = 0; i < resultTop; i++)
    {
        (*returnColumnSizes)[i] = length[i];
    }
    return result;
}

// 回溯
// 难点在于如何保证result中没有重复的path，即去重

// 所有组合问题都可以抽象成树的结构
// 去重分为 树层去重and树枝去重
// 本题是result中的path不能重复， 但是path中可以有相等的不同元素（指下标不同）
// 所以是树层去重
// 去重的思路是 
// 1. 排序-用qsort方法 -> 相等元素一定相邻
// 2. i > start && candidates[i] == candidates[i - 1] 是核心
//     i > start的作用是确保只在当前递归的层次中检查重复
