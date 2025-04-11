// 3492. 船上可以装载的最大集装箱数量
// 给你一个正整数 n，表示船上的一个 n x n 的货物甲板。甲板上的每个单元格可以装载一个重量 恰好 为 w 的集装箱。

// 然而，如果将所有集装箱装载到甲板上，其总重量不能超过船的最大承载重量 maxWeight。

// 请返回可以装载到船上的 最大 集装箱数量。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxContainers(int n, int w, int maxWeight)
    {
        return min(maxWeight / w, n * n);
    }
};


// 这题纯阅读理解
