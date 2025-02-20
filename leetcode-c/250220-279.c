// 279. 完全平方数
// 中等

// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
// 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
// 例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

#define MAXN 10000
int numSquares(int n) {
    int nums[101];
    for(int i = 0; i <= 100; i++){
        nums[i] = i * i;
    }

    // dp[i]: 和为i的完全平方数的最小数量
    int* dp = malloc(sizeof(int) * (n + 1));
    for(int i = 0; i <= n; i++){
        dp[i] = MAXN;
    }
    dp[0] = 0;

    // 遍历
    for(int j = 0; j <= 100; j++){
        for(int i = nums[j]; i <= n; i++){
            dp[i] = fmin(dp[i], dp[i - nums[j]] + 1);
        }
    }
    // print
    for(int i = 0; i <= n; i++){
        printf("%d ", dp[i]);
    }
    return dp[n];


}

