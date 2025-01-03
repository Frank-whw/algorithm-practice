// 122. 买卖股票的最佳时机 II
// 中等

// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
// 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。
// 你也可以先购买，然后在 同一天 出售。
// 返回 你能获得的 最大 利润 。

// 示例 1：
// 输入：prices = [7,1,5,3,6,4]
// 输出：7
// 解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
// 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
// 最大总利润为 4 + 3 = 7 。

// int maxProfit(int* prices, int pricesSize) {
//     int * profit = malloc(sizeof(int) * (pricesSize - 1));
//     for(int i = 1; i < pricesSize; i++){
//         profit[i - 1] = prices[i] - prices[i - 1];
//     }
//     int sum = 0;
//     for(int i = 0; i < pricesSize - 1; i ++){
//         if(profit[i] > 0) {
//             sum += profit[i];
//         }
//     }
//     return sum;
// }  

// 以上代码能过 但是太蠢了
int maxProfit(int *prices, int pricesSize) {
    int result = 0;
    for(int i = 1; i < pricesSize; i++){
        if(prices[i] > prices[i - 1]){
            result += prices[i] - prices[i - 1];
        }
    }
    return result;
}

// 贪心
// 局部最优 -> 全局最优
// prices[3] - prices[1] = prices[3] - prices[2] + prices[2] - prices[1] 
// 最终利润是可以分解的