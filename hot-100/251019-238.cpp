// 238. 除自身以外数组的乘积

// 中等

// 提示
// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
// 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        vector<int> preTime(n, 1);
        vector<int> beTime(n, 1);
        for (int i = 1; i < n; i++)
        {
            preTime[i] = preTime[i - 1] * nums[i - 1]; // 元素i的前缀乘积
        }
        for (int i = n - 2; i >= 0; i--)
        {
            beTime[i] = nums[i + 1] * beTime[i + 1];
        }
        for (int i = 0; i < n; i++)
        {
            ans.push_back(preTime[i] * beTime[i]);
        }
        return ans;
    }
};


// 通过preTime 和 beTime 分别记录元素 i 的前缀元素 后缀元素的乘积
// 2次遍历
// 空间/时间复杂度O(N)



// 空间复杂度O(1)的解法
// 由于输出数组不算在空间复杂度内，那么我们可以将 L 或 R 数组用输出数组来计算。
// 先把输出数组当作 L 数组来计算，然后再动态构造 R 数组得到结果。


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);
        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }
        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i];
        }
        return answer;
    }
};

