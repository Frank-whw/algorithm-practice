// 2845. 统计趣味子数组的数目
// 中等

// 提示
// 给你一个下标从 0 开始的整数数组 nums ，以及整数 modulo 和整数 k 。
// 请你找出并统计数组中 趣味子数组 的数目。
// 如果 子数组 nums[l..r] 满足下述条件，则称其为 趣味子数组 ：
// 在范围 [l, r] 内，设 cnt 为满足 nums[i] % modulo == k 的索引 i 的数量。并且 cnt % modulo == k 。
// 以整数形式表示并返回趣味子数组的数目。

// 注意：子数组是数组中的一个连续非空的元素序列。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        using ll = long long;
        ll result = 0;
        // 用滑动窗口做
        int left = 0, right = 0, n = nums.size(), count;
        vector<int> prefix(n + 1); // 前缀和数组
        // partial_sum(nums.begin(), nums.end(), prefix.begin());
        prefix[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + (nums[i - 1] % modulo == k ? 1 : 0);
        }

        // 暴力，发现卡在609/617，需要用哈希优化一下

        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = i + 1; j <= n; j++)
        //     {
        //         int count = prefix[j] - prefix[i];
        //         if (count % modulo == k)
        //         {
        //             result += 1;
        //         }
        //     }
        // }
        return result;
    }
};


// 下面是官方题解

// 我们用哈希表 cnt 存储当前已遍历的前缀中 sum[i]mod modulo 的数目，
// 每次从小到大枚举索引 r，此时期望可以快速找到以 r 为右边届的趣味子数组的数目，
// 即找到满足条件的左边界 l 的数目。根据上述推论可知，
// 此时只需要在哈希表 cnt 中找到等于 (sum[r]−k+modulo)mod modulo 的数目，
// 即为满足条件的左边界的数目，将其累加到结果中，最后返回总的累加结果即可。
// 为了优化计算，此时特殊元素的前缀和可以用单个变量 prefix 表示即可。

class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long res = 0;
        int prefix = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; i++)
        {
            prefix += nums[i] % modulo == k;
            res += cnt[(prefix - k + modulo) % modulo];
            cnt[prefix % modulo]++;
        }
        return res;
    }
};
