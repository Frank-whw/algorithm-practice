// 01背包

// 有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
// 每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。

// 输入：
// 第一行包含两个正整数，第一个整数 M 代表物品的个数，第二个正整数 N，代表背包的空间。
// 第二行包含 M 个正整数，代表每个物品的所占空间。
// 第三行包含 M 个正整数，代表每个物品的价值。
// 输出：
// 最大价值

//*使用一维滚动dp数组

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
    // dp[i]指的是容量为i时可以放置物品的最大价值
    int *dp = malloc(sizeof(int) * N);
    // 全初始化为0
    for (int j = 0; j < N; j++)
    {
        dp[j] = 0;
    }

    // 开始遍历
    for (int i = 1; i < M; i++)
    {
        for(int j = M; j >= weight[i]; j--){
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    printf("%d", dp[N - 1]);
}

// 纯01背包
// 1. dp[j]的定义：表示在背包容量为 j 时能获得的最大价值
// 2. 初始化状态
//     全设置为0
// 3. 状态方程转移，即递归方程，需分情况
//    1. 当前物品放不下，即dp[j] = dp[j]
//    2. 放得下：需要考虑 放 or 不放，取max
// 4. 遍历求解

// 把二维dp数组压为一维的核心在于：拷贝+覆盖
// 注意此时要从右向左更新数组
// 原因在于：1.每一个dp[j]是根据“上”和“上左”的dp来确定的，在一维数组中的体现就是dp[j]和dp[j-weight[i]]
//          2.倒序遍历是为了保证物品i只被放入一次