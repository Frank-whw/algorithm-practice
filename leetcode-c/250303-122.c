// 122. 买卖股票的最佳时机 II
// 中等

// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
// 在每一天，你可以决定是否购买和/或出售股票。
// 你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
// 返回 你能获得的 最大 利润 。
int maxProfit(int *prices, int pricesSize)
{
    // dp[i][0]:第i天有股票的最大利润
    int **dp = malloc(sizeof(int *) * pricesSize);
    for (int i = 0; i < pricesSize; i++)
    {
        dp[i] = malloc(sizeof(int) * 2);
    }

    // 初始化
    dp[0][0] = 0;
    dp[0][1] = 0 - prices[0];

    // 遍历
    for (int i = 1; i < pricesSize; i++)
    {
        dp[i][0] = fmax(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = fmax(dp[i - 1][0] - prices[i], dp[i - 1][1]);
    }
    for (int i = 0; i < pricesSize; i++)
    {
        printf("%d %d\n", dp[i][0], dp[i][1]);
    }

    return dp[pricesSize - 1][0];
}

// 挺有意思的点在于这道题是我一开始的理解
// 第i天如果买入股票的话，手上的钱是上一天没有股票时候手上的钱-当天的股价
