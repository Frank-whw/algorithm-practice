// 3493. 属性图
// 给你一个二维整数数组 properties，其维度为 n x m，以及一个整数 k。

// 定义一个函数 intersect(a, b)，它返回数组 a 和 b 中 共有的不同整数的数量 。

// 构造一个 无向图，其中每个索引 i 对应 properties[i]。如果且仅当 intersect(properties[i], properties[j]) >= k（其中 i 和 j 的范围为 [0, n - 1] 且 i != j），节点 i 和节点 j 之间有一条边。

// 返回结果图中 连通分量 的数量

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfComponents(vector<vector<int>> &properties, int k)
    {
        int n = properties.size();
        vector<bitset<101>> bs(n);
        for (int i = 0; i < n; i++)
        {
            for (int val : properties[i])
            {
                bs[i].set(val);
            }
        }
        // Union-Find initialization
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        function<int(int)> findp = [&](int x) -> int
        {
            return parent[x] == x ? x : parent[x] = findp(parent[x]);
        };
        auto unionp = [&](int x, int y)
        {
            int rx = findp(x), ry = findp(y);
            if (rx != ry)
            {
                parent[ry] = rx;
            }
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((int)((bs[i] & bs[j]).count()) >= k)
                {
                    unionp(i, j);
                }
            }
        }
        // unordered_set 自动去重
        unordered_set<int> comps;
        for(int i = 0; i < n; i++){
            comps.insert(findp(i));
        }
        return comps.size();
    }
};