// 01背包

// 有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
// 每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。

// 输入：
// 第一行包含两个正整数，第一个整数 M 代表物品的个数，第二个正整数 N，代表背包的空间。
// 第二行包含 M 个正整数，代表每个物品的所占空间。
// 第三行包含 M 个正整数，代表每个物品的价值。
// 输出：
// 最大价值

#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    int *weight = malloc(sizeof(int) * M);
    int *value = malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &value[i]);
    }
    // dp[i][j]指的是容量为j时，前i个物品的最大价值
    int **dp = malloc(sizeof(int *) * M);
    for (int i = 0; i < M; i++)
    {
        dp[i] = malloc(sizeof(int) * N);
    }

    // 初始化
    // i = 0的情况 只考虑一个物品
    for (int j = 0; j < N; j++)
    {
        if (j >= weight[0])
        {
            dp[0][j] = value[0];
        }
        else
        {
            dp[0][j] = 0;
        }
    }
    // j = 0的情况 容量为0
    for (int i = 0; i < M; i++)
    {
        dp[i][0] = 0;
    }

    // 开始遍历
    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (j < weight[i])
            {
                // 当前物品无法放入背包
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // 取放入和不放入当前物品的最大值
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    printf("%d", dp[M - 1][N]);
}

// 纯01背包
// 1. dp[i][j]的定义：表示在前 i 个物品中选择，背包容量为 j 时能获得的最大价值
// 2. 初始化状态
//     i = 0:只考虑第一个物品
//     j = 0:容量为0
// 3. 状态方程转移，即递归方程，需分情况
//    1. 当前物品放不下，即dp[i][j] = dp[i-1][j]
//    2. 放得下：需要考虑 放 or 不放，取max
// 4. 遍历求解