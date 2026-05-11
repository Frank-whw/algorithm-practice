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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sk;
        while (root != nullptr || !sk.empty())
        {
            while (root)
            {
                sk.push(root);
                root = root->left;
            }
            root = sk.top(); sk.pop();
            k--;
            if(k == 0) break;
            root = root->right;
        }
        return root->val;
        
    }
};