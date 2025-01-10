// 96. 不同的二叉搜索树
// 中等

// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？
// 返回满足题意的二叉搜索树的种数。

int numTrees(int n) {
    int* dp = malloc(sizeof(int) * (n + 1));
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j <= i; j++){
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];
}


// 动态规划
// 这道题确定递推关系有点难
// 别的没啥