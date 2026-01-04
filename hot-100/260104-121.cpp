// 121. 买卖股票的最佳时机
// 简单

// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                result = max(result, prices[j] - prices[i]);
            }
            
        }
        return result;
        
    }
};

// 暴力超时
// 实际上，如果第 i 天卖，那最大收益的情况是 前 i-1 天中的最低点买入
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < min_price){
                min_price = prices[i];
            }else if(prices[i] - min_price > max_profit){
                max_profit = prices[i] - min_price;
            }
        }
        return max_profit;

        
    }
};