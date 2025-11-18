// 102. 二叉树的层序遍历

// 中等

// 提示
// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。
//  （即逐层地，从左到右访问所有节点）。

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (!root)
            return ans;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> num;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                num.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(num);
        }
        return ans;
    }
};