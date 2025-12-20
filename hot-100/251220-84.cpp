// 84. 柱状图中最大的矩形

// 困难

// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

// 求在该柱状图中，能够勾勒出来的矩形的最大面积。

#include <bits/stdc++.h>
using namespace std;
// 暴力
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        int max_area = 0;
        // 对于每一个柱子 向左向右遍历 直到遇到高度小于 h 的柱子，确定左右边界
        for (int i = 0; i < heights.size(); i++)
        {
            int left = i, right = i, h = heights[i];
            while (left >= 0 && heights[left] >= h)
            {
                left--;
            }
            while (right < heights.size() && heights[right] >= h)
            {
                right++;
            }
            max_area = max(max_area, h * (right - left - 1));
        }
        return max_area;
    }
};

// 只能通过 93/99

// 栈
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> s;
        int len = heights.size();
        int area = 0;
        for (int i = 0; i < len; i++)
        {
            while (!s.empty() && heights[s.top()] > heights[i])
            {
                int h = heights[s.top()];
                s.pop();
                int width = i;
                if (!s.empty())
                {
                    width = i - s.top() - 1;
                }
                area = max(area, h * width);
            }
            s.push(i);
        }
        while (!s.empty())
        {
            int h = heights[s.top()];
            s.pop();
            int width = len;
            if (!s.empty())
            {
                width = len - s.top() - 1;
            }
            area = max(area, h * width);
        }
        return area;
    }
};