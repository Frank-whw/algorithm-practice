// 583. 两个字符串的删除操作
// 中等

// 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

// 每步 可以删除任意一个字符串中的一个字符。

int minDistance(char *word1, char *word2)
{
    // dp[i][j]:word1[:i] & word2[:j]所需的步数
    int **dp = malloc(sizeof(int *) * (strlen(word1) + 1));
    for (int i = 0; i <= strlen(word1); i++)
    {
        dp[i] = malloc(sizeof(int) * (strlen(word2) + 1));
    }
    // 初始化
    for (int i = 0; i <= strlen(word1); i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= strlen(word2); j++)
    {
        dp[0][j] = j;
    }
    // 遍历
    for (int i = 1; i <= strlen(word1); i++)
    {
        for (int j = 1; j <= strlen(word2); j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = fmin(dp[i][j - 1], dp[i - 1][j]) + 1;
            }
        }
    }
    for (int i = 0; i <= strlen(word1); i++)
    {
        for (int j = 0; j <= strlen(word2); j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return dp[strlen(word1)][strlen(word2)];
}

// 此类题型是很熟练了现在