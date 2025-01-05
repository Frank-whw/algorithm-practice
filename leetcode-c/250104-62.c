// 62. 不同路径
// 中等

// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
// 问总共有多少条不同的路径？

int uniquePaths(int m, int n) {
    int table[101][101];
    for(int i = 0; i < m;i++)   table[i][0] = 1;
    for(int i = 0; i < n;i++)   table[0][i] = 1;
    
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
    }
    return table[m - 1][n - 1];
}

// dp
// 简单题 但不熟练