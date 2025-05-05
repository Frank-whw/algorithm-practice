// 1920. 基于排列构建数组
// 简单

// 提示
// 给你一个 从 0 开始的排列 nums（下标也从 0 开始）。
// 请你构建一个 同样长度 的数组 ans ，其中，对于每个 i（0 <= i < nums.length），
// 都满足 ans[i] = nums[nums[i]] 。返回构建好的数组 ans 。

// 从 0 开始的排列 nums 是一个由 0 到 nums.length - 1（
// 0 和 nums.length - 1 也包含在内）的不同整数组成的数组。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++)
        {
            result[i] = nums[nums[i]];
        }
        return result;
    }
};