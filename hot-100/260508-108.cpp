/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int s, int e) {
        if(s >= e)  return nullptr;
        int mid = s + (e - s) / 2;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = sortedArrayToBST(nums, s, mid);
        head->right = sortedArrayToBST(nums, mid + 1, e);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
};

// 看了251119-108的代码
// 直接用return new TreeNode(nums[mid], sortedArrayToBST(nums, start, mid), sortedArrayToBST(nums, mid + 1, end));