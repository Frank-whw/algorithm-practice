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
    bool helper(TreeNode* node, long long maxV, long long minV){
        if(!node)    return true;
        return  maxV > node->val && node->val >minV && helper(node->left, node->val, minV) && helper(node->right, maxV,node->val);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MAX, LONG_MIN);
    }
};