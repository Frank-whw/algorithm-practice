// 226. 翻转二叉树

// 简单

// 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)     return nullptr;
        TreeNode* temp1 = invertTree(root->left);
        TreeNode* temp2 = invertTree(root->right);
        root->left = temp2;
        root->right = temp1;
        return root;
    }
};