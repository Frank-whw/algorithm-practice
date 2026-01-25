// 5. 最长回文子串
// 中等

// 给你一个字符串 s，找到 s 中最长的 回文 子串。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // dp[i][j]表示 s[i+1 : j-1]是回文串
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 0;
        int start = 0;
        // dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
        for(int i = n - 1; i >= 0; i--){
            for (int j = i; j < n; j++)
            {
                if(i == j)  dp[i][j] = true;
                else if(s[i] == s[j]){
                    dp[i][j] = j - i == 1|| dp[i + 1][j - 1];
                }
                
                if(dp[i][j] && j - i + 1 > ans){
                    ans = j - i + 1;
                    start = i;
                }
            }
            
        }
        return s.substr(start, ans);
        
    }
};