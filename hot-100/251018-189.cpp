// 189. 轮转数组

// 中等

// 提示
// 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[(i + k) % n] = nums[i];
        }
        nums = ans;
    }
};

// 注意ans[(i + k) % n] = nums[i];
// 如果写成 ans[i] = nums[(i + n - k) % n];会溢出，如果 i + n - k < 0