class Solution {
public:
    // it seems to use bfs so that we can get the min minutes
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(!fresh)  return 0;
        int minutes = 0;
        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while(!q.empty()){
            bool rottedThisMinute = false;
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx, dy] : dirs){
                    int nx = x + dx, ny = y + dy;
                    if(nx >= 0 && nx < row && ny >= 0 && ny < col
                    && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        rottedThisMinute = true;
                    }
                }
            }
            if (rottedThisMinute) {
                minutes++;
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};


