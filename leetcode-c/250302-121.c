// 121. 买卖股票的最佳时机
// 简单

// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
// 设计一个算法来计算你所能获取的最大利润。
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

int maxProfit(int *prices, int pricesSize)
{
    // dp[i][0]:第i天有股票的最大利润
    int **dp = malloc(sizeof(int*) * pricesSize);
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
        dp[i][1] = fmax(- prices[i], dp[i - 1][1]);
    }
    for(int i = 0; i < pricesSize; i++){
        printf("%d %d\n", dp[i][0], dp[i][1]);
    }

    return dp[pricesSize-1][0];
}

// dp
// 乍一看没有思路，但其实还好
// 读题出现偏差，以为可以无限次买入卖出
// 但思路没错