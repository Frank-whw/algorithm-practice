// 994. 腐烂的橘子
// 算术评级: 4
// 1433

// 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

// 值 0 代表空单元格；
// 值 1 代表新鲜橘子；
// 值 2 代表腐烂的橘子。
// 每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

// 返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int direction[4][2] = {1, 0, -1 ,0, 0, 1, 0, -1}; 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1)    cnt++;
            }
        }
        int ans = -1;
        while (!q.empty())
        {
            int size = q.size();
            ans++;
            for(int i = 0; i < size; i++){
                auto [x, y] = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    int x_next = x + direction[j][0];
                    int y_next = y + direction[j][1];
                    if(x_next >= 0 && x_next < grid.size() &&
                       y_next >= 0 && y_next < grid[0].size() &&
                       grid[x_next][y_next] == 1){
                        cnt--;
                        grid[x_next][y_next] = 2;
                        q.push({x_next, y_next});
                       }
                }
            }
        }

        return cnt ? -1 : max(ans, 0);
    }
};

// 广度优先搜索 队列