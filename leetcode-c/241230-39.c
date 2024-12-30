// 39. 组合总和
// 中等
// 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
// 找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。

// 示例 1：
// 输入：candidates = [2,3,6,7], target = 7
// 输出：[[2,2,3],[7]]
// 解释：
// 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
// 7 也是一个候选， 7 = 7 。
// 仅有这两种组合。

int *path;
int **result;
int pathTop;
int resultTop;

void backtracking(int *candidates, int candidatesSize, int target, int startIndex, int currentSum, int **returnColumnSizes)
{
    if (currentSum > target)
        return;
    if (currentSum == target)
    {
        int *copyPath = malloc(sizeof(int) * pathTop);
        for (int i = 0; i < pathTop; i++)
        {
            copyPath[i] = path[i];
        }
        result[resultTop] = copyPath;
        (*returnColumnSizes)[resultTop] = pathTop; // 记录当前组合的长度
        resultTop++;
        return;
    }
    for (int i = startIndex; i < candidatesSize; i++)
    {
        path[pathTop++] = candidates[i];
        backtracking(candidates, candidatesSize, target, i, currentSum+candidates[i], returnColumnSizes);
        pathTop--;
    }
}
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    path = malloc(sizeof(int) * 1000);
    result = malloc(sizeof(int *) * 1000);
    *returnColumnSizes = malloc(sizeof(int) * 1000);
    pathTop = 0;
    resultTop = 0;
    // 开始回溯
    backtracking(candidates, candidatesSize, target, 0, 0, returnColumnSizes);

    // 设置返回结果
    *returnSize = resultTop;
    return result;
}

// 回溯
// 难度不大，但还是不够熟练