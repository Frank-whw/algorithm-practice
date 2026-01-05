// 55. 跳跃游戏

// 中等

// 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。

// 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxStep = nums[0];
        for(int i = 0; i <= maxStep; i++){
            if(maxStep >= n - 1)    return true;
            maxStep = max(maxStep, nums[i] + i);
        }
        return false;
    }
};
// 遍历每一个位置 并维护 maxStep 记录最远可以到达的位置