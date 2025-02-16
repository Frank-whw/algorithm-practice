// 518. 零钱兑换 II
// 中等

// 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
// 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
// 假设每一种面额的硬币有无限个。
// 题目数据保证结果符合 32 位带符号整数。

unsigned long long change(int amount, int *coins, int coinsSize)
{
    // 定义dp[i][j]：前i种硬币组成j面额的组合数
    unsigned long long **dp = malloc(sizeof(unsigned long long *) * coinsSize);
    for (int i = 0; i < coinsSize; i++)
    {
        dp[i] = malloc(sizeof(unsigned long long) * (amount + 1));
    }

    // 初始化
    for (int i = 0; i < coinsSize; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            dp[i][j] = 0;
        }
    }
    // i = 0
    for (int j = 0; j <= amount; j++)
    {
        if (j % coins[0] == 0)
        {
            dp[0][j] = 1;
        }
    }
    // j = 0
    for (int i = 0; i < coinsSize; i++)
    {
        dp[i][0] = 1;
    }

    // 遍历
    for (int i = 1; i < coinsSize; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (coins[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
        }
    }

    return dp[coinsSize - 1][amount];
}

// 完全背包问题
// dp
// dp[i][j]：使用 下标为[0, i]的coins[i]能够凑满j（包括j）这么大容量的包，有dp[i][j]种组合方法。
