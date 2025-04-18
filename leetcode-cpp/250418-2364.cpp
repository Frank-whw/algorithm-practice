// 2364. 统计坏数对的数目
// 中等

// 提示
// 给你一个下标从 0 开始的整数数组 nums 。如果 i < j 且 j - i != nums[j] - nums[i] ，那么我们称 (i, j) 是一个 坏数对 。

// 请你返回 nums 中 坏数对 的总数目。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 暴力，但是超出时间限制，时间复杂度O(n^2)

    // long long countBadPairs(vector<int> &nums)
    // {
    //     int n = nums.size(), count = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             if (j - i != nums[j] - nums[i])
    //             {
    //                 count += 1;
    //             }
    //         }
    //     }
    //     return count;
    // }

    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<long long, long long> arr; // 用来存储nums[i] - i
        int n = nums.size();
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            long long key = nums[i] - i;
            count += arr[key];
            arr[key] += 1;
        }
        long long all_case = n / 2.0 * (n - 1) ;
        return all_case - count;
    }
};

// 还是很有意思的一道题，我一开始并没有想到移项以降低计算量，这很致命
// 慢慢熟悉cpp的写法
// 时间复杂度O(n)
// 我想的是先算出所有好数对的数目，然后再用总数做差

// 有个更优的思路是
// res += i - mp[nums[i] - i];
// res：坏数对的数量
// i：本应该增加i个数对
// mp[nums[i] - i]: 其中有#个好数对
