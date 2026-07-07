/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // return the lowest common ancestor
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(!root || root == p || root == q){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left && right){
            return root;
        }
        return left ? left : right;
    }
};

class Solution {
    public:
        // noticed that the key of each map is 'int'
        unordered_map<int, TreeNode*> father; // record the father of each node
        unordered_map<int, int> visited; // record whether each node has been visited

        void dfs(TreeNode *root){
            if(root->left){
                father[root->left->val] = root;
                dfs(root->left);
            }
            if(root->right){
                father[root->right->val] = root;
                dfs(root->right);
            }
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            father[root->val] = nullptr;
            dfs(root); // set all node's father
            // visited the fathers of the p node
            while(p != nullptr){
                visited[p->val] = 1;
                p = father[p->val];
            }
            while(q != nullptr){
                if(visited[q->val]) return q;
                q = father[q->val];
            }
            return nullptr;
        }
    };

    
