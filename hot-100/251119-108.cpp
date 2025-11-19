// 108. 将有序数组转换为二叉搜索树

// 简单

// 给你一个整数数组 nums ，
// 其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return sortedArrayToBST(nums, 0, n);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
        if(end - 1 == start)    return new TreeNode(nums[start]);
        if(end -1 - start == 1){
            return new TreeNode(nums[start], nullptr, new TreeNode(nums[end - 1]));
        }
        int mid = start + (end - start) / 2;
        return new TreeNode(nums[mid], sortedArrayToBST(nums, start, mid), sortedArrayToBST(nums, mid + 1, end));

    }
};

// 一遍过！ 重载+递归

// 优化一下
// 代码虽然简洁了，但是栈空间变多，反而不如我的方法，多几次判断 但是少递归次数

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return sortedArrayToBST(nums, 0, n);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
        if(end - 1 < start)    return nullptr;

        int mid = start + (end - start) / 2;
        return new TreeNode(nums[mid], sortedArrayToBST(nums, start, mid), sortedArrayToBST(nums, mid + 1, end));

    }
};