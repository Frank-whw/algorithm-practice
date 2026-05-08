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
class Solution {
public:
    int hight(TreeNode * node){
        if(node == nullptr) return 0;
        return max(hight(node->left), hight(node->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(   max(   hight(root->right) + hight(root->left)  , diameterOfBinaryTree(root->left))   , diameterOfBinaryTree(root->right));
    }
};

// 思路：hight计算每个节点的最大高度，diameterOfBinaryTree则是判断 max（以当前节点为顶的路径，以左子节点为顶的路径，以右子节点为顶的路径）
// 有重复计算

class Solution {
public:
    int ans = 0;
    int hight(TreeNode * node){
        if(node == nullptr) return 0;
        int lh = hight(node->left);
        int rh = hight(node->right);
        ans = max(ans, lh + rh);
        return max(lh, rh) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        hight(root);
        return ans;
    }
};