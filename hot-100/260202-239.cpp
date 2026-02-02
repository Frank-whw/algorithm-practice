// 239. 滑动窗口最大值

// 困难

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
        vector<int> result(n - k + 1);
        deque<int> dq;
        // 队列头部始终是当前窗口的最大值索引

        for (int i = 0; i < n; i++)
        {
            // 1.移除超出窗口左边界的元素
            while (!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }
            // 2.移除dq中比当前元素小的元素，保证队列单调递减
            while (!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }
            // 3.入队
            dq.push_back(i);
            // 4.记录最大值
            if (i >= k - 1)
            {
                result[i - k + 1] = nums[dq.front()];
            }
        }
        return result;
    }
};