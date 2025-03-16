// 1143. 最长公共子序列
// 中等

// 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

// 一个字符串的 子序列 是指这样一个新的字符串：
// 它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
// 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

int longestCommonSubsequence(char *text1, char *text2)
{
    // dp[i][j]: text1前i个元素和text2前j个元素，且以text1[i] == text2[j]结尾的最长公共子序列
    int **dp = malloc(sizeof(int *) * (strlen(text1) + 1));
    for (int i = 0; i <= strlen(text1); i++)
    {
        dp[i] = malloc(sizeof(int) * (strlen(text2) + 1));
    }
    // 初始化
    for (int i = 0; i <= strlen(text1); i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= strlen(text2); j++)
    {
        dp[0][j] = 0;
    }

    // 遍历
    for (int i = 1; i <= strlen(text1); i++)
    {
        for (int j = 1; j <= strlen(text2); j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                // printf("%c\n", text1[i - 1]);
                dp[i][j] = dp[i-1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // for (int i = 0; i <= strlen(text1); i++)
    // {
    //     for (int j = 0; j <= strlen(text2); j++)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return dp[strlen(text1)][strlen(text2)];
}

// 通过慢慢刷题，总结动态规划题型的基本特征
// 当不确定递推关系时，可以通过手算出dp[i][j]，然后和程序的dp对比，找到不符合的点定点爆破解决