// 72. 编辑距离

// 中等

// 给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

// 你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = dp[0][j - 1] + 1;
        }
        for (int i = 1; i <= n; i++)
        {
            char c1 = word1[i - 1];
            for (int j = 1; j <= m; j++)
            {
                char c2 = word2[j - 1];
                if (c1 == c2)
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
            }
        }
        return dp[n][m];
    }
};