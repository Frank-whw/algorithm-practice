// 322. 零钱兑换

// 中等

// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

// 你可以认为每种硬币的数量是无限的。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= coins[j] && dp[i - coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }

        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};

// 优化：
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 1.边界情况
        if (amount == 0)
            return 0;
        // 2.过滤无效硬币
        vector<int> validCoins;
        for (int coin : coins)
        {
            if (coin > 0 && coin <= amount)
                validCoins.push_back(coin);
        }
        if (validCoins.empty())
            return -1;
        sort(validCoins.begin(), validCoins.end());
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for(int coin : validCoins){
                if(coin > i)    break;
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }

        return dp[amount] <= amount ? dp[amount] : -1;
    }
};