// 279. 完全平方数

// 中等

// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

// 完全平方数 是一个整数，其值等于另一个整数的平方；
// 换句话说，其值等于一个整数自乘的积。
// 例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        // dp[i]: 和为n的完全平方数的最少数量
        dp[0] = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];

    }
};