// 647. 回文子串
// 中等

// 提示
// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
// 回文字符串 是正着读和倒过来读一样的字符串。
// 子字符串 是字符串中的由连续字符组成的一个序列。

#include <stdbool.h>
int countSubstrings(char *s)
{
    // dp[i][j]:s[i:j+1]是否构成回文字符串
    int result = 0;
    bool **dp = malloc(sizeof(bool *) * strlen(s));
    for (int i = 0; i < strlen(s); i++)
    {
        dp[i] = malloc(sizeof(bool) * strlen(s));
        for (int j = 0; j < strlen(s); j++)
        {
            dp[i][j] = false;
        }
    }
    // 遍历
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        for (int j = i; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i <= 1)
                {
                    result++;
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1])
                {
                    result++;
                    dp[i][j] = true;
                }
            }
        }
    }

    return result;
}

// dp
// dp数组的定义不太好想
// 递推关系也比较迷
// 此类求回文子串的思路都是枚举中间然后往2边延申