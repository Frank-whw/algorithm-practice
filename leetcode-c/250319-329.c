// 392. 判断子序列

// 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

// 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
// （例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

// 进阶：

// 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，
// 你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

#include <stdbool.h>
bool isSubsequence(char *s, char *t)
{
    bool **dp = malloc(sizeof(bool *) * (strlen(s) + 1));
    for (int i = 0; i <= strlen(s); i++)
    {
        dp[i] = malloc(sizeof(bool) * (strlen(t) + 1));
    }
    // 初始化
    for (int i = 0; i <= strlen(s); i++)
    {
        dp[i][0] = false;
    }
    for (int j = 0; j <= strlen(t); j++)
    {
        dp[0][j] = true;
    }
    // 遍历
    for (int i = 1; i <= strlen(s); i++)
    {
        for (int j = 1; j <= strlen(t); j++)
        {
            dp[i][j] = s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : dp[i][j - 1];
        }
    }
    return dp[strlen(s)][strlen(t)];
}
