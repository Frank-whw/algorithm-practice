// 94. 二叉树的中序遍历
// 简单

// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

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
    void inorder(TreeNode* node, vector<int> &res){
        if(!node)   return;
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};