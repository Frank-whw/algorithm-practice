// 139. 单词拆分

// 中等

// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
// 如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。

// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_set<string> wordSet;
        for(auto word : wordDict){
            wordSet.insert(word);
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(dp[j] && wordSet.find(s.substr(j, i-j)) != wordSet.end()){
                    dp[i] = true;
                    break;
                }
            }
            
        }
        return dp[n];
    }
};

// 涉及到字符串的题还是有点不熟练