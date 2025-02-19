// 322. 零钱兑换
// 中等

// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。
// 如果没有任何一种硬币组合能组成总金额，返回 -1 。
// 你可以认为每种硬币的数量是无限的。

#define MAXN 1000000
int coinChange(int* coins, int coinsSize, int amount) {
    // dp[i]: 组成i的最少硬币个数
    int* dp = malloc(sizeof(int) * (amount + 1));
    for(int i = 0; i <= amount; i++){
        dp[i] = MAXN;
    }
    dp[0] = 0;

    // 遍历
    for(int j = 0; j < coinsSize; j++){
        for(int i = coins[j]; i <= amount; i++){
            dp[i] = fmin(dp[i],dp[i - coins[j]] + 1);
        }
    }

    // print
    for(int i = 0; i <= amount; i++){
        printf("%d ", dp[i]);
    }
    return dp[amount] == MAXN ? -1 : dp[amount];
}

// 完全背包问题