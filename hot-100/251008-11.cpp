// 11. 盛最多水的容器
// 中等

// 提示
// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
// 返回容器可以储存的最大水量。
// 说明：你不能倾斜容器。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        // int ans = 0;
        // for(int left = 0; left < height.size() - 1;left++){
        //     for(int right = left + 1; right < height.size(); right++){
        //         int h = min(height[left], height[right]);
        //         int a = right - left;
        //         ans = max(ans, a * h);
        //     }
        // } 
        // return ans;

        // 超时
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while(left < right){
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
        // left++和right--都是为了尝试取到更多的水，
        // 如果短的板不动的话，取到的水永远不会比上次多
        // 在极大值里找最大值
    }
};