// 72. 编辑距离
// 中等

// 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

// 你可以对一个单词进行如下三种操作：
// 插入一个字符
// 删除一个字符
// 替换一个字符

int minDistance(char *word1, char *word2)
{
    // dp[i][j]:word1[:i]andword2[:j]所需要的最少操作数
    int **dp = malloc(sizeof(int *) * (strlen(word1) + 1));
    for (int i = 0; i <= strlen(word1); i++)
    {
        dp[i] = malloc(sizeof(int) * (strlen(word2) + 1));
    }

    // 初试化
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
                dp[i][j] = fmin(fmin(dp[i - 1][j], dp[i][j - 1]),dp[i-1][j-1]) + 1;
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