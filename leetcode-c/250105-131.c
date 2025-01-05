// 131. 分割回文串
// 中等

// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是
// 回文串
// 返回 s 所有可能的分割方案。

// 示例 1：
// 输入：s = "aab"
// 输出：[["a","a","b"],["aa","b"]]

// 示例 2：
// 输入：s = "a"
// 输出：[["a"]]

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

char ***result;
int resultTop;
char **current;
int currentTop;
int *resultSize;

int isPalindrome(char *str, int startIndex, int endIndex)
{
    while (endIndex >= startIndex)
    {
        if (str[endIndex--] != str[startIndex++])
        {
            return 0;
        }
    }
    return 1;
}

char *cutString(char *str, int startIndex, int endIndex)
{
    char *temp = malloc(sizeof(char) * (endIndex - startIndex + 2));
    int i, index = 0;
    for (i = startIndex; i <= endIndex; i++)
    {
        temp[index++] = str[i];
    }
    temp[index] = '\0';
    return temp;
}
void copy()
{
    char **temp = malloc(sizeof(char *) * currentTop);
    for (int i = 0; i < currentTop; i++)
    {
        temp[i] = malloc(strlen(current[i]) + 1); // 为每个字符串分配内存
        strcpy(temp[i], current[i]);              // 复制字符串内容
        printf("%d: %s\n", i, temp[i]);
    }
    result[resultTop] = temp;
    resultSize[resultTop++] = currentTop;
}

void backtracking(char *s, int sLength, int startIndex)
{
    if (startIndex >= sLength)
    {
        copy();
        return;
    }
    for (int i = startIndex; i < sLength; i++)
    {
        if (isPalindrome(s, startIndex, i))
        {
            current[currentTop++] = cutString(s, startIndex, i);
        }
        else
        {
            continue;
        }
        backtracking(s, sLength, i + 1);
        currentTop -= 1;
    }
}
char ***partition(char *s, int *returnSize, int **returnColumnSizes)
{
    result = malloc(sizeof(char **) * 40000);
    current = malloc(sizeof(char *) * 40000);
    resultSize = malloc(sizeof(int) * 40000);
    resultTop = currentTop = 0;
    int sLength = strlen(s);
    // printf("%d", sLength);
    backtracking(s, sLength, 0);

    *returnSize = resultTop;
    *returnColumnSizes = malloc(sizeof(int) * resultTop);
    for (int i = 0; i < resultTop; i++)
    {
        (*returnColumnSizes)[i] = resultSize[i];
    }
    return result;
}

// 回溯
// 较难
// 难点：
// 1.如何由切割想到回溯，其实可以抽象为组合问题
// 2.涉及到c语言字符串
// 3.很多细节处理：判断回文，截取字符串
// 整体下来，还是有很大问题的，需要后续复习