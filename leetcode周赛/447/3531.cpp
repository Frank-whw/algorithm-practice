// 3531. 统计被覆盖的建筑
// 给你一个正整数 n，表示一个 n x n 的城市，
// 同时给定一个二维数组 buildings，
// 其中 buildings[i] = [x, y] 表示位于坐标 [x, y] 的一个 唯一 建筑。

// 如果一个建筑在四个方向（左、右、上、下）中每个方向上都至少存在一个建筑，
// 则称该建筑 被覆盖 。

// 返回 被覆盖 的建筑数量

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {

        vector<int> l(n + 1, INT_MAX);
        vector<int> r(n + 1, INT_MIN);
        vector<int> u(n + 1, INT_MAX);
        vector<int> d(n + 1, INT_MIN);
        for (const auto &b : buildings)
        {
            int x = b[0];
            int y = b[1];
            l[x] = min(l[x], y);
            r[x] = max(r[x], y);
            u[y] = min(u[y], x);
            d[y] = max(d[y], x);
        }
        int res = 0;
        for (const auto &b : buildings)
        {
            int x = b[0];
            int y = b[1];
            if (y > l[x] && y < r[x] && x > u[y] && x < d[y])
            {
                res++;
            }
        }
        return res;
    }
};