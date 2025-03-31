// 763. 划分字母区间
// 中等

// 提示
// 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，
// 同一字母最多出现在一个片段中。例如，字符串 "ababcc" 能够被分为 ["abab", "cc"]，
// 但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。

// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

// 返回一个表示每个字符串片段的长度的列表。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *partitionLabels(char *s, int *returnSize)
{
    int *result = malloc(sizeof(int) * strlen(s));
    int resultSize = 0;
    // use to label the last Position of every letter
    int lastPosition[27] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        lastPosition[s[i] - 'a'] = i;
    }
    // for (int i = 0; i < 26; i++)
    // {
    //     printf("%c %d\n", (char)('a' + i), lastPosition[i]);
    // }
    int right = 0, left = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        right = fmax(right, lastPosition[s[i] - 'a']);
        if (i == right)
        {
            result[resultSize++] = right - left + 1;
            left = i + 1;
        }
    }
    *returnSize = resultSize;
    return result;
}

// 局部最优？

// 没有思路