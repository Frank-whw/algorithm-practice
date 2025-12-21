// 215. 数组中的第K个最大元素

// 中等

// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

class Solution
{
private:
    int quick_select(vector<int> &nums, int left, int right, int k)
    {
        if (left == right)
            return nums[left];
        int partition = nums[left], i = left - 1, j = right + 1;
        while (i < j)
        {
            do
                i++;
            while (nums[i] < partition);
            do
                j--;
            while (nums[j] > partition);
            if (i < j)
                swap(nums[i], nums[j]);
        }
        if (k <= j)
            return quick_select(nums, left, j, k);
        else return quick_select(nums, j + 1, right, k);
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return quick_select(nums, 0, nums.size() - 1, nums.size() - k);
    }
};