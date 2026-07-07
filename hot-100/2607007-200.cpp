class Solution {
    public:
        void dfs(vector<vector<char>>& grid, int r, int c){
            int nr = grid.size();
            int nc = grid[0].size();
    
            grid[r][c] = '0';
            if(r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
            if(r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
            if(c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
            if(c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
        }
        int numIslands(vector<vector<char>>& grid) {
            int nr = grid.size();
            int nc = grid[0].size();
    
            int res = 0;
            for(int i = 0; i < nr; i++) {
                for(int j = 0; j < nc; j++){
                    if(grid[i][j] == '1'){
                        res ++;
                        dfs(grid, i, j);
                    }
                }
            }
            return res;
        }
    };