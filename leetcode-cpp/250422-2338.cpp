// 2338. 统计理想数组的数目
// 困难

// 提示
// 给你两个整数 n 和 maxValue ，用于描述一个 理想数组 。

// 对于下标从 0 开始、长度为 n 的整数数组 arr ，如果满足以下条件，则认为该数组是一个 理想数组 ：

// 每个 arr[i] 都是从 1 到 maxValue 范围内的一个值，其中 0 <= i < n 。
// 每个 arr[i] 都可以被 arr[i - 1] 整除，其中 0 < i < n 。
// 返回长度为 n 的 不同 理想数组的数目。由于答案可能很大，返回对 1e9 + 7 取余的结果。

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

/*
class Solution
{
public:
    int idealArrays(int n, int maxValue)
    {
        int result = 0;
        using ll = long long;
        // dp[i][j]:以i结尾，长度为j的理想数组数量
        vector<vector<ll>> dp(n + 1, vector<ll>(maxValue + 1, 0));

        for (int j = 0; j <= maxValue; j++)
        {
            dp[1][j] = 1; // 长度为1
        }
        // 遍历

        // 思路正确代码正确，时间复杂度有点高
        // for (int i = 2; i <= n; i++)
        // {
        //     for (int j = 1; j <= maxValue; j++)
        //     {
        //         for (int k = 1; k <= j; k++)
        //         {
        //             if (j % k == 0)
        //             {
        //                 // 被整除
        //                 dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        //             }
        //         }
        //     }
        // }



        // 优化方向：枚举因数k，然后处理其所有倍数j（j = k, 2k, 3k...）
        // 时间复杂度从O(n*V^2)优化到O(n*V*logV)，V=maxValue
        for (int i = 2; i <= n; i++)
        {
            for (int k = 1; k <= maxValue; k++)
            { // 枚举所有可能的因数k
                if (dp[i - 1][k] == 0)
                    continue; // 如果k在上一层没有贡献，直接跳过
                for (int j = k; j <= maxValue; j += k)
                { // j是k的倍数，满足j%k==0
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }

        // 遍历最后一层
        for (int j = 1; j <= maxValue; j++)
        {
            result = (result + dp[n][j]) % MOD;
        }
        return result;
    }
};
*/

// 超出内存限制，下面优化思路是把二维数组压缩成2个一维数组
class Solution
{
public:
    int idealArrays(int n, int maxValue)
    {
        vector<long long> prev(maxValue + 1, 0);
        vector<long long> curr(maxValue + 1, 0);

        // 初始化长度为1的情况（prev表示i-1层，初始时i=1，对应prev是i=1的情况）
        for (int j = 1; j <= maxValue; j++)
        {
            prev[j] = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            fill(curr.begin(), curr.end(), 0); // 重置当前层
            for (int k = 1; k <= maxValue; k++)
            {
                if (prev[k] == 0)
                    continue; // 剪枝：无前驱状态则跳过
                for (int j = k; j <= maxValue; j += k)
                {
                    curr[j] = (curr[j] + prev[k]) % MOD;
                }
            }
            prev = curr; // 滚动数组，当前层变为下一层的前驱
        }

        long long result = 0;
        for (int j = 1; j <= maxValue; j++)
        {
            result = (result + prev[j]) % MOD;
        }
        return static_cast<int>(result);
    }
};

// 又超出时间限制，
// 第一次遇见dp做不成的题