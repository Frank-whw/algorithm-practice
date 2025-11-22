// 199. 二叉树的右视图

// 中等

// 给定一个二叉树的 根节点 root，
// 想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

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
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> ans;
        if (!root)
            return ans;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (i == 0)
                    ans.push_back(node->val);
                if(node->right)     q.push(node->right);
                if(node->left)      q.push(node->left);  
            }
        }
        return ans;
    }
};

// 一遍过
// 层序遍历 先放右子树，所以front是最右边的node