// 98. 验证二叉搜索树

// 中等

// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

// 有效 二叉搜索树定义如下：

// 节点的左子树只包含 严格小于 当前节点的数。
// 节点的右子树只包含 严格大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。

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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
    bool isValidBST(TreeNode* root, long long max, long long min) {
        if(root == nullptr) return true;
        if (root->val <= min || root->val >= max) {
            return false;
        }
        bool lflag = isValidBST(root->left, root->val, min);
        bool rflag = isValidBST(root->right, max, root->val);
        
        return lflag && rflag;
    }
};