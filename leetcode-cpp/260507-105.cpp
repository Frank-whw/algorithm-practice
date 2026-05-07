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
    int getIndex(vector<int> & arr, int tar){
        for(int i =0 ; i < arr.size(); i++){
            if(arr[i] == tar){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, int i, int j, vector<int>& inorder, int m ,int n){
        TreeNode* head = new TreeNode(preorder[i]);

        int index = getIndex(inorder, preorder[i]);
        head->left = helper(preorder, i + 1, j, inorder, m, index); // 
        head->right = helper(preorder, )
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }
};


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
    int getIndex(vector<int> & arr, int tar){
        for(int i =0 ; i < arr.size(); i++){
            if(arr[i] == tar){
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return nullptr;
        }
        TreeNode* head = new TreeNode(preorder[0]);

        int index = getIndex(inorder, preorder[0]);
        head->left = buildTree(preorder.sub(1, index), inorder.size(0, index))

        head->right = buildTree(preorder.sub(index + 1, inorder.size()) , inorder.sub(index + 1, inorder.size())); //
        return head;
    }
};