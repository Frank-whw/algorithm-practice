// 287. 寻找重复数
// 中等

// 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），
// 可知至少存在一个重复的整数。

// 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

// 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

#include <bits/stdc++.h>
using namespace std;

// 法一：哈希表
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        for (int n : nums)
        {
            if (set.find(n) != set.end())
            {
                return n;
            }
            set.insert(n);
        }
        return 0;
    }
};

// 法二：双指针
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2, count = 0;
            for (int i = 0; i <= n; i++)
            {
                if (nums[i] <= mid)
                    count++;
            }
            if (count <= mid)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

// 法三：利用数组元素和下标的对应关系，把元素放到它 “本该在的位置”，
// 时间复杂度 O (n)、空间复杂度 O (1)，效率很高

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0] != nums[nums[0]]){
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};