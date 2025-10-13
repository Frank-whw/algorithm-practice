// 239. 滑动窗口最大值
// 困难

// 提示
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0 || k == 0) return ans;
        
        int maxIndex = 0;
        // 找到第一个窗口的最大值索引
        for (int i = 0; i < k; ++i) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        ans.push_back(nums[maxIndex]);
        
        // 滑动窗口开始移动
        for (int r = k; r < n; ++r) {
            int l = r - k + 1; // 当前窗口左边界
            
            // 情况1：当前最大值仍在窗口内（未滑出）
            if (maxIndex >= l) {
                // 只需比较新加入的元素和当前最大值
                if (nums[r] >= nums[maxIndex]) {
                    maxIndex = r;
                }
            } 
            // 情况2：当前最大值已滑出窗口
            else {
                // 重新在当前窗口[l..r]中寻找最大值
                maxIndex = l; // 从左边界开始
                for (int i = l; i <= r; ++i) {
                    if (nums[i] > nums[maxIndex]) {
                        maxIndex = i;
                    }
                }
            }
            
            ans.push_back(nums[maxIndex]);
        }
        
        return ans;
    }
};

// runtime error
// 使用优先队列

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};