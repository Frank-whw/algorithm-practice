// 124. 二叉树中的最大路径和

// 困难

// 二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
// 同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

// 路径和 是路径中各节点值的总和。

// 给你一个二叉树的根节点 root ，返回其 最大路径和 。

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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
    // 返回以node节点为首的最大路径和(无分叉)
    int dfs(TreeNode* node){
        if(!node)    return 0;
        int left = max(dfs(node->left), 0);
        int right = max(dfs(node->right), 0);
        int val = left + right + node->val;
        ans = max(ans, val);
        return node->val + max(left, right);
    }
};

// dfs返回的是无分叉的最大值，这样方便复用，否则出现违规路径