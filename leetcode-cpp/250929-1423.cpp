// 1423. 可获得的最大点数
// 中等

// 提示
// 几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。

// 每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。

// 你的点数就是你拿到手中的所有卡牌的点数之和。

// 给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // int ans =0 ;
        // for(int num : cardPoints){
        //     ans += num;
        // }
        // int size = cardPoints.size() - k;
        // int minCount = 0;
        // for(int i = 0; i < size; i++){
        //     minCount += cardPoints[i];
        // }
        // int curCount = minCount;
        // for(int right = size; right < cardPoints.size(); right++){
        //     curCount = curCount - cardPoints[right - size] + cardPoints[right];
        //     minCount = curCount < minCount ? curCount : minCount;
        // }
        // return ans - minCount;

        
        int n = cardPoints.size();
        // 滑动窗口大小为n-k
        int windowSize = n - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
        int minSum = sum;
        for (int i = windowSize; i < n; i++){
            sum += cardPoints[i] - cardPoints[i - windowSize];
            minSum = min(minSum, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
    }
};