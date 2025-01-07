// 波动数列

// 观察这个数列：1 3 0 2 -1 1 -2 ...
// 这个数列中后一项总是比前一项增加2或者减少3。

// 栋栋对这种数列很好奇，他想知道长度为 n 和为 s 而且后一项总是比前一项增加a或者减少b的
// 整数数列可能有多少种呢？

// 输入
// 输入的第一行包含四个整数 n s a b，含义如前面说述。
// 输出
// 输出一行，包含一个整数，表示满足条件的方案数。由于这个数很大，请输出方案数除以100000007的余数。

// 输入 4 10 2 3
// 输出 2

#include <stdio.h>  
#define MOD 100000007
#define N 1000010
// const int MOD = 100000007;  
// const int N = 1000010;  
int dp[N];  

void create(int n) {  
    dp[0] = 1;  
    for (int i = 1; i < n; i++) {  
        for (int j = i * (i + 1) / 2; j >= i; j--) {  
            dp[j] = (dp[j] + dp[j - i]) % MOD;  
        }  
    }  
}  

int main() {  
    long long n, a, b, s; // 使用 long long 型以避免溢出  
    scanf("%lld %lld %lld %lld", &n, &s, &a, &b);  
    long long num = (n - 1) * n / 2;  
    long long optnum = a + b;  
    s += num * b; // 更新 s 的值  

    create(n); // 生成 dp 数组  

    int ans = 0;  
    for (int i = 0; i <= num; i++) {  
        long long temp = s - i * optnum;  
        if (temp % n == 0) {  
            ans = (ans + dp[i]) % MOD; // 满足条件时累加  
        }  
    }  

    printf("%d\n", ans); // 输出结果  
    return 0;  
}
