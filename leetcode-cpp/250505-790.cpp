// 790. 多米诺和托米诺平铺
// 中等

// 有两种形状的瓷砖：一种是 2 x 1 的多米诺形，另一种是形如 "L" 的托米诺形。
// 两种形状都可以旋转。

// 给定整数 n ，返回可以平铺 2 x n 的面板的方法的数量。返回对 10^9 + 7 取模 的值。

// 平铺指的是每个正方形都必须有瓷砖覆盖。
// 两个平铺不同，当且仅当面板上有四个方向上的相邻单元中的两个，
// 使得恰好有一个平铺有一个瓷砖占据两个正方形。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int MOD = 1'000'000'007;

public:
    int numTilings(int n)
    {
        vector<int> dp(n + 5, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        dp[4] = 11;
        for (int i = 5; i <= n; i++)
        {
            dp[i] = (dp[i - 1] // 加一个竖着的多米诺
                     + dp[i - 2]) %
                    MOD; // 加二个横着的多米诺
            for (int j = i - 3; j >= 0; j--)
            {
                dp[i] = (dp[i] + (long long)dp[j] * 2 % MOD) % MOD;
            }
        }
        return dp[n];
    }
};

// 思路正确
// 官方最优解对递推公式进行了化简

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        long f[n + 1];
        f[0] = f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; ++i)
            f[i] = (f[i - 1] * 2 + f[i - 3]) % MOD;
        return f[n];
    }
};