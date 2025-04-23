// 1399. 统计最大组的数目
// 简单

// 提示
// 给你一个整数 n 。请你先求出从 1 到 n 的每个整数 10 进制表示下的数位和（每一位上的数字相加），
// 然后把数位和相等的数字放到同一个组中。

// 请你统计每个组中的数字数目，并返回数字数目并列最多的组有多少个。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int counti(int n)
    {
        int res = 0;
        while (n)
        {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    int countLargestGroup(int n)
    {
        vector<int> count(37, 0);
        for (int i = 1; i <= n; i++)
        {
            count[counti(i)]++;
        }
        int res = 0, maxnum = 0;
        for (int i = 1; i < 37; i++)
        {
            if (count[i] == maxnum)
                res++;
            if (count[i] > maxnum)
            {
                maxnum = count[i];
                res = 1;
            }
        }
        return res;
    }
};

// 简单题
// 直接暴力模拟