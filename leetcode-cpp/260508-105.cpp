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
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, int i, int j, vector<int>& inorder, int m, int n){
        if(i >= j || m >= n)    return nullptr;
        if(i == j - 1 && m == n - 1)    return new TreeNode(preorder[i]);
        TreeNode* head = new TreeNode(preorder[i]);
        int index = mp[preorder[i]];
        head->left = buildTree(preorder, i + 1, i + 1 + index - m, inorder, m, index);
        head->right = buildTree(preorder, j - (n - index) + 1 ,j, inorder, index + 1, n);
        return head;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 建立inorder[i] 到 i 的索引
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        
    }
};