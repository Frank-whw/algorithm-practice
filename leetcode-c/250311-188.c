// 188. 买卖股票的最佳时机 IV
// 困难
// 给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

int maxProfit(int k, int *prices, int pricesSize)
{
    // 0:never,2i-1:ith have,2i:ith dont have
    int **dp = malloc(sizeof(int *) * pricesSize);
    for (int i = 0; i < pricesSize; i++)
    {
        dp[i] = malloc(sizeof(int) * (2 * k + 1));
        for (int j = 0; j <= 2 * k; j++)
        {
            dp[i][j] = 0;
        }
    }
    // 初始化
    for (int j = 1; j <= k; j++)
    {
        dp[0][2 * j - 1] = -prices[0];
    }

    // 遍历
    for (int i = 1; i < pricesSize; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][2 * j - 1] = fmax(dp[i - 1][2 * j - 1], dp[i - 1][2 * j - 2] - prices[i]);
            dp[i][2 * j] = fmax(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] + prices[i]);
        }
    }

    for (int i = 0; i < pricesSize; i++)
    {
        for (int j = 0; j <= 2 * k; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return dp[pricesSize - 1][2 * k];
}

// dp
// 递推公式，状态转移方程不难想到
// 难点在于设计dp数组