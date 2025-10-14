// 239. 滑动窗口最大值
// 困难

// 提示
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++)
        {
            q.emplace(nums[i], i);
        }
        vector<int> ans;
        ans.push_back(q.top().first);
        for (int i = k; i < n; i++)
        {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k)
            {
                q.pop();
            }
            ans.push_back(q.top().second);
        }
        return ans;
    }
};