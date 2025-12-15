// 4. 寻找两个正序数组的中位数

// 困难

// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
// 请你找出并返回这两个正序数组的 中位数 。

// 算法的时间复杂度应该为 O(log (m+n)) 。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        int len = m + n;
        int a = 0, b = 0; // the index of the next num of nums1 and nums2 respectively
        int left = -1, right = -1;
        for (int i = 0; i <= len / 2; i++)
        {
            left = right;
            if (a < n && (b >= m || nums1[a] < nums2[b]))
            {
                right = nums1[a++];
            }
            else
            {
                right = nums2[b++];
            }
        }
        if (len % 2 == 0)
        {
            return (left + right) / 2.0;
        }
        else
        {
            return right;
        }
    }
};

// 类似双指针解法，用 a 和 b 指向 nums1 nums2的第一个元素
// 算法复杂度是 O(m+n)

// O(log(m+n)): 二分查找找第k小元素 


class Solution {
public:
    // 辅助函数：找两个有序数组中第k小的元素（k从1开始）
    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0, j = 0; // 两个数组的起始索引
        int n = nums1.size(), m = nums2.size();
        while (true) {
            // 边界1：nums1已遍历完，直接返回nums2的第k个元素
            if (i == n) return nums2[j + k - 1];
            // 边界2：nums2已遍历完，直接返回nums1的第k个元素
            if (j == m) return nums1[i + k - 1];
            // 边界3：k=1，返回最小值
            if (k == 1) return min(nums1[i], nums2[j]);
            
            // 计算步长（避免越界）
            int step = k / 2;
            int new_i = min(i + step, n) - 1; // nums1的比较位置
            int new_j = min(j + step, m) - 1; // nums2的比较位置
            
            // 排除更小的部分，缩小k
            if (nums1[new_i] <= nums2[new_j]) {
                k -= (new_i - i + 1); // 排除nums1[i..new_i]
                i = new_i + 1;
            } else {
                k -= (new_j - j + 1); // 排除nums2[j..new_j]
                j = new_j + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (len % 2 == 1) {
            // 奇数：第 len//2 + 1 小的元素
            return findKth(nums1, nums2, len / 2 + 1);
        } else {
            // 偶数：第 len//2 和 len//2 + 1 小的元素的平均
            return (findKth(nums1, nums2, len / 2) + findKth(nums1, nums2, len / 2 + 1)) / 2.0;
        }
    }
};