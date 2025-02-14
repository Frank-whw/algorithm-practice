// 完全背包
// 模板
// 有N件物品和一个最多能背重量为W的背包。
// 第i件物品的重量是weight[i]，得到的价值是value[i] 。
// 每件物品都有无限个（也就是可以放入背包多次），
// 求解将哪些物品装入背包里物品价值总和最大。

#include <stdio.h>

int main()
{
    int N, W;
    scanf("%d", &N, &W);
    int *weight = malloc(sizeof(int) * N);
    int *value = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &weight[i], &value[i]);
    }

    // 定义dp[i][j]：前i个物品 放进容量为j的背包的最大价值
    int **dp = malloc(sizeof(int *) * N);
    for (int i = 0; i <= N; i++)
    {
        dp[i] = malloc(sizeof(int) * (W + 1));
    }

    // 初始化
    // i = 0
    for (int j = 0; j <= W; j++)
    {
        if (j >= weight[0])
        {
            dp[0][j] = dp[0][j - weight[0]] + value[0];
        }
        else
        {
            dp[0][j] = 0;
        }
    }
    // j = 0
    for (int i = 0; i < N; i++)
    {
        dp[i][0] = 0;
    }

    // 遍历
    for(int i = 1; i <N; i++){
        for(int j = 0; j <= W; j++){
            if(j < weight[i]){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
            }
        }
    }

    printf("%d", dp[N - 1][W]);
}