// 2563. 统计公平数对的数目
// 中等

// 提示
// 给你一个下标从 0 开始、长度为 n 的整数数组 nums ，
// 和两个整数 lower 和 upper ，返回 公平数对的数目 。

// 如果 (i, j) 数对满足以下情况，则认为它是一个 公平数对 ：
// 1. 0 <= i < j < n，且
// 2. lower <= nums[i] + nums[j] <= upper

#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// private:
//     // 找到第一个大于等于 target 的元素的索引
//     int left_binarySearch(const vector<int> &nums, int start, int target)
//     {
//         int left = start, right = nums.size();
//         while (left < right)
//         {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] < target)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid;
//             }
//         }
//         return left;
//     }
//     // 找到第一个大于 target 的元素的索引
//     int right_binarySearch(const vector<int> &nums, int start, int target)
//     {
//         int left = start, right = nums.size();
//         while (left < right)
//         {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] <= target)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid;
//             }
//         }
//         return left;
//     }

// public:
//     long long countFairPairs(vector<int> &nums, int lower, int upper)
//     {
//         using ll = long long;
//         ll result = 0;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int left = lower - nums[i];
//             int right = upper - nums[i];
//             int l = left_binarySearch(nums, i + 1, left);
//             int r = right_binarySearch(nums, i + 1, right);
//             cout << l << " & " << r << endl;

//             result += r - l;
//             // cout << i << ": " << r - l << endl;
//         }
//         return result;
//     }
// };

// 第一想法是排序然后对于每一个数，分别找到left和right，中间的值即为符合要求的数

// 优化：可以联想到滑动窗口，双指针

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        using ll = long long;
        ll result = 0;
        sort(nums.begin(), nums.end());
        int l = nums.size(), r = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            while (l && nums[l - 1] >= lower - nums[i])
            {
                l--;
            }
            while (r && nums[r - 1] > upper - nums[i])
            {
                r--;
            }
            result += min(r, i) - min(l, i);
        }
        return result;
    }
};