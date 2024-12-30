// 17. 电话号码的字母组合
// 中等
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
// 答案可以按 任意顺序 返回。
// 给出数字到字母的映射如下（与电话按键相同）。
// 注意 1 不对应任何字母。

// 2->abc
// 3->def
// 4->ghi
// 5->jkl
// 6->mno
// 7->pqrs
// 8->tuv
// 9->wxyz

char letter[10][5] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void backtracking(char *digits, char **result, char *current, int *returnSize, int curSize)
{
    if (curSize == strlen(digits))
    {
        // result[(*returnSize)++] = current;
        result[(*returnSize)++] = strdup(current); // 保存当前组合
        return;
    }
    int digit = digits[curSize] - '0';
    for (int i = 0; letter[digit][i] != '\0'; i++)
    {
        current[curSize] = letter[digit][i];
        backtracking(digits, result, current, returnSize, curSize + 1);
    }
}
char **letterCombinations(char *digits, int *returnSize)
{
    if (digits == NULL || strlen(digits) == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int len = strlen(digits);
    char **result = malloc(sizeof(char *) * 10000);
    char *current = malloc(sizeof(char) * (len + 1));
    *returnSize = 0;
    current[len] = '\0';
    backtracking(digits, result, current, returnSize, 0);
    free(current);
    return result;
}

// 回溯
// 组合题
// 有几个问题：
// 1. strdup的用法是什么？
    //  strdup 是一个 C 标准库函数，它的作用是复制给定的字符串并返回一个新的字符串指针
    // strdup(current) 是将 current 中的字母组合保存到 result 数组中，
    // 并且由于 current 是一个局部变量，复制它是必要的，
    // 否则当递归返回时，current 会被覆盖，导致原来的字母组合丢失
// 2. 为什么returnSize前要加'*'？
    // 改变*returnSize的值就是通过地址来修改全局变量的值
