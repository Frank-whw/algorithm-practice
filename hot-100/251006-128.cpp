// 128. 最长连续序列
// 中等

// 相关企业
// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set;
        for (int &num : nums)
        {
            num_set.insert(num); // 先去重
        }
        int ans = 0;
        for (int num : num_set)
        {
            // 如果num_set里面没有num-1
            if (!num_set.count(num - 1))
            {
                int curNum = num;
                int curLength = 1;
                while (num_set.count(curNum + 1))
                {
                    curNum++;
                    curLength++;
                }
                ans = max(ans, curLength);
            }
        }
        return ans;
    }
};