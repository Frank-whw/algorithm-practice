// 714. 买卖股票的最佳时机含手续费
// 中等

// 提示
// 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；
// 整数 fee 代表了交易股票的手续费用。
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
// 返回获得利润的最大值。
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

int maxProfit(int *prices, int pricesSize, int fee)
{
    // dp[i][0]: ith day dont have
    int **dp = malloc(sizeof(int *) * pricesSize);
    for (int i = 0; i < pricesSize; i++)
    {
        dp[i] = malloc(sizeof(int) * 2);
    }

    // initialize
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
        dp[i][0] = fmax(dp[i - 1][1] - fee + prices[i], dp[i - 1][0]);
        dp[i][1] = fmax(dp[i - 1][0] - prices[i], dp[i - 1][1]);
    }
    for (int i = 0; i < pricesSize; i++)
    {
        printf("%d %d\n", dp[i][0], dp[i][1]);
    }
    return dp[pricesSize - 1][0];
}

// 虽然变了 但是还是很简单
// 整体思路还是抓住递推关系，状态转移方程