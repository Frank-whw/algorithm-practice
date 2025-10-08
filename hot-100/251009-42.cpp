// 42. 接雨水


// 困难

// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        for(int i = 1; i < n - 1;i++){
            int l = i - 1, r = i + 1;
            // 只要右边更低，就跳过当前
            if(height[r] < height[i])  continue;
            // 找到左边界
            while(l > 0 && height[l] <= height[l-1]){
                l--;
            }
            // 找到右边界，r为右侧最大值或者第一个height大于等于height[l]
            int maxIndex = r;
            while(r < n - 1 && height[r] < height[l]){
                r++;
                if(height[maxIndex] < height[r]){
                    maxIndex = r;
                }
            }
            r = maxIndex;
            // 找到2个边界对应的height的最小值
            int min_height = min(height[l], height[r]);
            for(int j = l + 1; j <= r - 1; j++){
                ans += min_height - height[j] > 0 ? min_height- height[j] : 0;
            }
            cout << i <<": " << l << " and " << r  <<  endl;

            i = r;
        }
        return ans;
    }
};

// yeah用自己的思路搓出来一道hard
// 大致思路是找到局部最小值，为每个位置找到左右边界，2个边界形成一个容器，计算容器的volume
// 然后直接跳到右边界，避免重复运算

// 看了官方题解，感觉自己就是five


// 1.动态规划
// 牛逼 真的妙
// 核心想法是 对于位置i，能接的高度为2边的最大高度的最小值
// 所以分别向左 向右遍历得到leftMax和rightMax，再取min

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};


// 2.单调栈
// 核心思路是通过一个单调递减栈记录【可能成为凹槽左边界的柱子】，如果遇到更高的柱子，就找到了凹槽的右边界

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};

// 3.双指针
// 核心思路是用双指针+2个变量代替法一中的leftMax和rightMax


class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};