// 70. 爬楼梯
// 简单
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 示例 1：
// 输入：n = 2
// 输出：2
// 解释：有两种方法可以爬到楼顶。
// 1. 1 阶 + 1 阶
// 2. 2 阶

int climbStairs(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int *dp = malloc(sizeof(int) * (n + 1));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 动态规划
// 一开始 我的想法是从实际意义出发，dp[0] = 0，但是wrong answer，为了ac 使dp[0] = 1
// 有点牵强
// 代码随想录给了一个想法：直接定义dp[1] = 1 dp[2] = 2，从i = 3开始递推
// 这样就可以避开dp[0] 妙
int climbStairs(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int *dp = malloc(sizeof(int) * (n + 1));
    dp[2] = 2;
    dp[1] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}