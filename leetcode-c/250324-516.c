// 516. 最长回文子序列
// 中等

// 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

// 子序列定义为：不改变剩余字符顺序的情况下，
// 删除某些字符或者不删除任何字符形成的一个序列。

int longestPalindromeSubseq(char *s)
{
    // dp[i][j]: s[i:j]回文子序列的最大长度
    int **dp = malloc(sizeof(int *) * strlen(s));
    for (int i = 0; i < strlen(s); i++)
    {
        dp[i] = malloc(sizeof(int) * strlen(s));
        for (int j = 0; j < strlen(s); j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else
                dp[i][j] = 0;
        }
    }
    // 遍历
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        for (int j = i; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                if (j - i == 2)
                {
                    // “aba”
                    dp[i][j] = 3;
                }
                else if (j - i == 1)
                {
                    // “aa”
                    dp[i][j] = 2;
                }
                else if (i + 1 < strlen(s) && j - 1 >= 0 && dp[i + 1][j - 1])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            }
            else
            {
                // “abac” ->"aba" / "bac"
                dp[i][j] = fmax(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][strlen(s) - 1];
}

// dp
// dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]

// 如果s[i]与s[j]不相同，说明s[i]和s[j]的同时加入 
// 并不能增加[i,j]区间回文子序列的长度，
// 那么分别加入s[i]、s[j]看看哪一个可以组成最长的回文子序列。