// 100554. 非递减数组的最大长度
// 给你一个整数数组 nums。在一次操作中，你可以选择一个子数组，并将其替换为一个等于该子数组 最大值 的单个元素。

// 返回经过零次或多次操作后，数组仍为 非递减 的情况下，数组 可能的最大长度。

// 子数组 是数组中一个连续、非空 的元素序列。

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int maximumPossibleSize(vector<int> &nums)
    {
        int length = 1;

        int key = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] >= key)
            {
                key = nums[i];
                length += 1;
            }
        }
        return length;
    }
};