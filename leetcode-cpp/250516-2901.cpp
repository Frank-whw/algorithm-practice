// 2901. 最长相邻不相等子序列 II
// 中等

// 提示
// 给你一个整数 n 和一个下标从 0 开始的字符串数组 words ，和一个下标从 0 开始的数组 groups ，两个数组长度都是 n 。

// 两个长度相等字符串的 汉明距离 定义为对应位置字符 不同 的数目。

// 你需要从下标 [0, 1, ..., n - 1] 中选出一个 最长子序列 ，将这个子序列记作长度为 k 的 [i0, i1, ..., ik - 1] ，它需要满足以下条件：

// 相邻 下标对应的 groups 值 不同。即，对于所有满足 0 < j + 1 < k 的 j 都有 groups[ij] != groups[ij + 1] 。
// 对于所有 0 < j + 1 < k 的下标 j ，都满足 words[ij] 和 words[ij + 1] 的长度 相等 ，且两个字符串之间的 汉明距离 为 1 。
// 请你返回一个字符串数组，它是下标子序列 依次 对应 words 数组中的字符串连接形成的字符串数组。如果有多个答案，返回任意一个。

// 子序列 指的是从原数组中删掉一些（也可能一个也不删掉）元素，剩余元素不改变相对位置得到的新的数组。

// 注意：words 中的字符串长度可能 不相等 。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOK(vector<string> &words, int i, int j)
    {
        if (words[i].size() != words[j].size())
        {
            return false;
        }
        int diff = 0;
        for (int k = 0; k < words[i].size(); k++)
        {
            if (words[i][k] != words[j][k])
            {
                diff++;
            }
        }
        return diff == 1 ? true : false;
    }
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        // dp[i]：以words[i]结尾的最长相邻不相等子序列
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        vector<string> res;
        int maxIndex = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isOK(words, i, j) && groups[i] != groups[j] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[maxIndex] < dp[i])
            {
                maxIndex = i;
            }
        }

        for (int i = maxIndex; i >= 0; i = prev[i])
        {
            res.emplace_back(words[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// 动态规划
// 设dp[i]表示以i为结尾的最长子序列长度

// 用 prev[i] 记载以下标 i 为结尾的最长子序列中 i 的上一个下标
// 这个挺有意思的i = prev[i]