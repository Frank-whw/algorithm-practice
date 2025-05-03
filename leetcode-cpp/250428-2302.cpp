// 2302. 统计得分小于 K 的子数组数目
// 困难

// 提示
// 一个数组的 分数 定义为数组之和 乘以 数组的长度。

// 比方说，[1, 2, 3, 4, 5] 的分数为 (1 + 2 + 3 + 4 + 5) * 5 = 75 。
// 给你一个正整数数组 nums 和一个整数 k ，
// 请你返回 nums 中分数 严格小于 k 的 非空整数子数组数目。

// 子数组 是数组中的一个连续元素序列。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        using ll = long long;
        ll result = 0;
        int n = nums.size();
        vector<ll> prefix(n + 1);
        partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
        // prefix[i + 1]:前i个元素的和
        // for (int num : prefix)
        // {
        //     cout << num << endl;
        // }
        int l = 0, r = 0;
        ll count = 0;
        while (r < n)
        {
            count = (r - l + 1) * (prefix[r + 1] - prefix[l]);
            while (count >= k)
            {
                l += 1;
                count = (r - l + 1) * (prefix[r + 1] - prefix[l]);
                cout << "l:" << l << " r:" << r << " cout: " << count << endl;
            }
            result += r - l + 1;

            // cout << "l:" << l << " r:" << r << " cout: " << count << endl;
            r++;
        }
        return result;
    }
};

// 第一想法是用前缀和去做，毕竟是新学的知识，总想着用上
// 以上解法通过了163/167个测试样例，死在runtime error上
// 但整体滑动窗口的思路是对的
// 下面附上官方题解

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int n = nums.size();
        long long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++)
        {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k)
            {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};
