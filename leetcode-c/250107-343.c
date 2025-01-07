// 343. 整数拆分
// 中等

// 提示
// 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
// 返回 你可以获得的最大乘积 。

// 示例 1:
// 输入: n = 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1。

int integerBreak(int n)
{
    int *dp = malloc(sizeof(int) * (n + 1));
    dp[2] = dp[1] = 1;
    for (int i = 3; i <= n; i++)
    {
        int max = 0;
        for (int j = 2; j < i; j++)
        {
            max = fmax(j * (i - j), j * dp[i - j]) > max ? fmax(j * (i - j), j * dp[i - j]) : max;
        }
        dp[i] = max;
    }
    return dp[n];
}

// 动态规划
// 难点在于如何找出递推关系
// 本题的思路是对于每一个i，用j从2遍历到i，比较取j*(i-j),j*dp[i-j],max的最大值