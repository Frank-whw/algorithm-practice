// 2894. 分类求和并作差
// 简单
// 相关标签
// 相关企业
// 提示
// 给你两个正整数 n 和 m 。

// 现定义两个整数 num1 和 num2 ，如下所示：

// num1：范围 [1, n] 内所有 无法被 m 整除 的整数之和。
// num2：范围 [1, n] 内所有 能够被 m 整除 的整数之和。
// 返回整数 num1 - num2 。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % m == 0)
            {
                num2 += i;
            }
            else
            {
                num1 += i;
            }
        }
        return num1 - num2;
    }
};