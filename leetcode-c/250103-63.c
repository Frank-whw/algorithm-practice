// 63. 不同路径 II
// 中等

// 提示
// 给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。
// 机器人每次只能向下或者向右移动一步。
// 网格中的障碍物和空位置分别用 1 和 0 来表示。
// 机器人的移动路径中不能包含 任何 有障碍物的方格。
// 返回机器人能够到达右下角的不同路径数量。

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    if (obstacleGrid[0][0] == 1){
        return 0;
    }
    int dp[101][101] = {0};
    int row = obstacleGridSize;
    int col = *obstacleGridColSize;
    for (int i = 0; i < row && obstacleGrid[i][0] == 0; i++){
        // printf("%d,%d", i,0);
        dp[i][0] = 1;
    }
    for (int j = 0; j < col && obstacleGrid[0][j] == 0; j++) 
    {
        // printf("%d,%d", 0,j);
        dp[0][j] = 1;
    }
    // printf("%d ", dp[0][1]);
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                // printf("%d,%d = %d + %d \n", i, j, dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // printf("%d %d\n", row, col);
    // for(int i = 0; i < row; i++){
    //     for(int j = 0; j < col; j++){
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return dp[row -1 ][col-1];
}


// dp
// 找路径
// 傻逼真傻逼
// 在运行中可以跑通，在提交中跑不通
// 原因在于，2者的环境下 int dp[101][101]初始值不同，前者是0，后者是1
// 哪有初始为1的啊