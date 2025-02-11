// 2370. 最长理想子序列
// 题目难度Medium
// 给你一个由小写字母组成的字符串 s ，和一个整数 k 。如果满足下述条件，则可以将字符串 t 视作是 理想字符串 ：

// t 是字符串 s 的一个子序列。
// t 中每两个 相邻 字母在字母表中位次的绝对差值小于或等于 k 。
// 返回 最长 理想字符串的长度。

// 字符串的子序列同样是一个字符串，并且子序列还满足：可以经由其他字符串删除某些字符（也可以不删除）但不改变剩余字符的顺序得到。

// 注意：字母表顺序不会循环。例如，'a' 和 'z' 在字母表中位次的绝对差值是 25 ，而不是 1 。

int longestIdealString(char* s, int k) {
    int dp[26] = {0};
    int len = strlen(s);

    int ans = 0;
    for (int i = 0; i < len; i++) {
        int index = s[i] - 'a';
        int left = fmax(index - k, 0);
        int right = fmin(index+k,25);

        int curMax = 0;
        for(int j = left; j <= right; j++){
            curMax = fmax(curMax, dp[j] + 1);
        }
        dp[index] = curMax;
        ans = fmax(ans, dp[index]);
    }

    return ans;
}
