// 123. 买卖股票的最佳时机 III
// 困难

// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

int maxProfit(int *prices, int pricesSize)
{
    // 0: 没有过  1：第一次有  2：第一次没有  3：第二次有  4：第二次没有
    int **dp = malloc(sizeof(int *) * pricesSize);
    for (int i = 0; i < pricesSize; i++)
    {
        dp[i] = malloc(sizeof(int) * 5);
        for (int j = 0; j < 5; j++)
        {
            dp[i][j] = 0;
        }
    }

    // 初始化
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
        dp[i][1] = fmax(dp[i - 1][1], -prices[i]);
        dp[i][2] = fmax(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = fmax(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = fmax(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[pricesSize - 1][4];
}
// 状态转移方程 不难想到
// 数组初始化 注意dp[0][3]的实际意义
