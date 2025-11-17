// 43. 二叉树的直径

// 简单

// 给你一棵二叉树的根节点，返回该树的 直径 。

// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。
// 这条路径可能经过也可能不经过根节点 root 。

// 两节点之间路径的 长度 由它们之间边数表示。

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
    int ans = 0;
    int height(TreeNode* node){
        if(!node)   return 0;
        int left = height(node->left), right = height(node->right);
        ans = max(ans, left + right); // 取每一个节点左右深度之和的最大值
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return max(ans, height(root->left) + height(root->right));
    }
};