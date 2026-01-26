// 1143. 最长公共子序列
// 中等

// 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。
// 如果不存在 公共子序列 ，返回 0 。

// 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下
// 删除某些字符（也可以不删除任何字符）后组成的新字符串。

// 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
// 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        // dp[i][j] 表示text1[0:i] 和 text2[0:j] 的最长公共子序列的长度
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = text1[0] == text2[0] ? 1 : 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = text1[i] == text2[0] ? 1 : dp[i - 1][0];
        }
        for (int j = 1; j < m; j++)
        {
            dp[0][j] = text1[0] == text2[j] ? 1 : dp[0][j - 1];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

// 优化1：简化初始化逻辑
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            char c1 = text1[i - 1];
            for (int j = 1; j <= m; j++)
            {
                char c2 = text2[j - 1];
                if (c1 == c2)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

// 优化2：降低空间复杂度
// 优化1的空间复杂度是O(m*n), dp[i][j]的值取决于 “上”，“左上”，“左”的值
// 所以考虑用一维数组代替二维数组，空间从O(n*m)→O(m)（m是较短字符串长度）
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        if(n < m) {
            swap(text1, text2);
            swap(n, m);
        }
        vector<int> dp(m, 0);

        // 先处理第一个字符的匹配情况
        dp[0] = (text1[0] == text2[0]) ? 1 : 0;
        for (int j = 1; j < m; j++) {
            dp[j] = (text1[0] == text2[j]) ? 1 : dp[j-1];
        }

        for (int i = 1; i < n; i++) {
            // 保存左上角的值（dp[i-1][j-1]），避免被覆盖后丢失
            int prev = dp[0]; // 初始为上一行第0列的值（dp[i-1][0]）
            // 更新当前行第0列（对应原二维数组的dp[i][0]）
            dp[0] = (text1[i] == text2[0]) ? 1 : dp[0];

            // 遍历较短字符串的每个字符
            for (int j = 1; j < m; j++) {
                // 先保存当前dp[j]（即上一行的dp[i-1][j]），后续作为下一个j的prev（左上角）
                int temp = dp[j];
                if (text1[i] == text2[j]) {
                    // 字符匹配：取左上角值（prev）+1
                    dp[j] = prev + 1;
                } else {
                    // 字符不匹配：取上边（temp）或左边（dp[j-1]）的最大值
                    dp[j] = max(temp, dp[j-1]);
                }
                // 更新prev为当前j的上一行值，供下一个j使用
                prev = temp;
            }
        }

        return dp[m-1];
    }
};