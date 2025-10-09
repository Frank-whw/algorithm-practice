// 42. 接雨水

// 困难

// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0, n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        if (n == 0)
            return 0;
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i - 1], height[i]);
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);
        for (int i = 0; i < n; i++)
        {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0, n = height.size();
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && height[i] > height[stk.top()])
            {
                int top = stk.top();
                stk.pop();
                if (stk.empty())
                {
                    // 说明没有左边界
                    break;
                }
                int left = stk.top();
                int width = i - left - 1;
                int h = min(height[left], height[i]) - height[top];
                ans += width * h;
            }
            stk.push(i);
        }
        return ans;
    }
};



class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0, n = height.size();
        int left = 0, right = n - 1;
        int leftMax = height[0], rightMax = height[n - 1];
        while(left  < right){
            if(height[left] < height[right]){
                left++;
                leftMax = max(leftMax, height[left]);
                ans += leftMax - height[left]; 
            }else{
                right--;
                rightMax = max(rightMax, height[right]);
                ans += rightMax - height[right];
            }
        }
        return ans;
    }
};