// 115. 不同的子序列
// 困难

// 给你两个字符串 s 和 t ，
// 统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 10^9 + 7 取模。

#define MOD 1000000007
int numDistinct(char *s, char *t)
{
    int **dp = malloc(sizeof(int *) * (strlen(t) + 1));
    for (int i = 0; i <= strlen(t); i++)
    {
        dp[i] = malloc(sizeof(int) * (strlen(s) + 1));
    }

    // 初始化
    for (int i = 0; i <= strlen(t); i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= strlen(s); j++)
    {
        dp[0][j] = 1;
    }

    // 遍历
    for (int i = 1; i <= strlen(t); i++)
    {
        for (int j = 1; j <= strlen(s); j++)
        {
            if (s[j - 1] == t[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[strlen(t)][strlen(s)] % MOD;
}

