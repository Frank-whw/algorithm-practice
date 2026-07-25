class Solution {
    public:
        vector<pair<int, int>> dirs ={
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        int orangesRotting(vector<vector<int>>& grid) {
            queue<pair<int, int>> q;
            int n = grid.size(), m = grid[0].size();
            int flesh_num = 0;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 1) flesh_num++;
                    if(grid[i][j] == 2){ 
                        q.push({i, j});
                    }
                }
            }
            if(flesh_num == 0)  return 0;
            int minutes = 0;
            
            while(!q.empty()){
                bool rotted = false;
                int size = q.size();
                for(int i = 0; i < size; i++){
                    auto [x, y] = q.front(); q.pop();
                    for(auto [dx, dy] : dirs){
                        int nx = x + dx, ny = y + dy;
                        if(nx >=0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                            cout << nx << " " << ny << endl;
                            grid[nx][ny] = 2;
                            flesh_num--;
                            q.push({nx, ny});
                            rotted = true;
                        }
                    }
                }
                if(rotted){
                    minutes++;
                }
            }

            return flesh_num == 0 ? minutes : -1;

        }
    };