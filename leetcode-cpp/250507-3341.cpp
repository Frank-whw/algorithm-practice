// 3341. 到达最后一个房间的最少时间 I
// 中等

// 提示
// 有一个地窖，地窖中有 n x m 个房间，它们呈网格状排布。

// 给你一个大小为 n x m 的二维数组 moveTime ，
// 其中 moveTime[i][j] 表示在这个时刻 以后 你才可以 开始 往这个房间 移动 。
// 你在时刻 t = 0 时从房间 (0, 0) 出发，每次可以移动到 相邻 的一个房间。
// 在 相邻 房间之间移动需要的时间为 1 秒。

// 请你返回到达房间 (n - 1, m - 1) 所需要的 最少 时间。

// 如果两个房间有一条公共边（可以是水平的也可以是竖直的），那么我们称这两个房间是 相邻 的。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = 0;
        // i = 0
        for (int j = 1; j < m; j++)
        {
            dp[0][j] = max(moveTime[0][j], dp[0][j - 1]) + 1;
        }

        // j =0
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(moveTime[i][0], dp[i - 1][0]) + 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = max(min(dp[i][j - 1], dp[i - 1][j]), moveTime[i][j]) + 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n - 1][m - 1];
    }
};

// 以上dp算法只能通过703/743个测试用例
// 原因在于：可以向上走，即拐弯
// 需要用到：最短路 + Dijkstra， 暂时不会
class Solution
{
    struct State
    {
        int x;
        int y;
        int dis;
        State(int x, int y, int dis) : x(x), y(y), dis(dis) {};
        bool operator<(const State &rth) const
        {
            return dis > rth.dis;
        }
    };

public:
    const int inf = 0x3f3f3f3f;
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<int>> v(n, vector<int>(m, 0));

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;
        priority_queue<State> q;
        q.push(State(0, 0, 0));

        while (q.size())
        {
            State s = q.top();
            q.pop();
            if (v[s.x][s.y])
            {
                continue;
            }
            v[s.x][s.y] = 1;
            for (int i = 0; i < 4; i++)
            {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                {
                    continue;
                }
                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + 1;
                if (d[nx][ny] > dist)
                {
                    d[nx][ny] = dist;
                    q.push(State(nx, ny, dist));
                }
            }
        }
        return d[n - 1][m - 1];
    }
};

