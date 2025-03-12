// 309. 买卖股票的最佳时机含冷冻期
// 中等

// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
// 设计一个算法计算出最大利润。在满足以下约束条件下，
// 你可以尽可能地完成更多的交易（多次买卖一支股票）:
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

int maxProfit(int *prices, int pricesSize)
{
    // 0：never have，1：have
    int **dp = malloc(sizeof(int *) * pricesSize);
    for (int i = 0; i < pricesSize; i++)
    {
        dp[i] = malloc(sizeof(int) * 2);
        for (int j = 0; j < 2; j++)
        {
            dp[i][j] = -1000;
        }
    }

    // 初始化
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
        dp[i][0] = fmax(dp[i - 1][1] + prices[i], dp[i - 1][0]);
        if (i >= 2)
            dp[i][1] = fmax(dp[i - 2][0] - prices[i], dp[i - 1][1]);
        else
            dp[i][1] = fmax(dp[i - 1][0] - prices[i], dp[i - 1][1]);
    }

    for (int i = 0; i < pricesSize; i++)
    {
        printf("%d %d\n", dp[i][0], dp[i][1]);
    }
    return dp[pricesSize - 1][0];
}

// 一般
// 虽然和代码随想录给的思路不同，但就我个人理解而言，更喜欢自己的思路