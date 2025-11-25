// 236. 二叉树的最近公共祖先
// 中等

// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
// 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    unordered_map<TreeNode *, vector<TreeNode *>> map;
    vector<TreeNode *> path;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root);
        vector<TreeNode *> pPath = map[p];
        vector<TreeNode *> qPath = map[q];
        for (int i = pPath.size() - 1; i >= 0; i--)
        {
            TreeNode *node = pPath[i];
            if (find(qPath, node))
                return node;
        }
        return nullptr;
    }
    bool find(vector<TreeNode *> path, TreeNode *node)
    {
        for (TreeNode *n : path)
        {
            if (n == node)
                return true;
        }
        return false;
    }
    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        path.push_back(node);
        map[node] = path;
        dfs(node->left);
        dfs(node->right);
        path.pop_back();
    }
};

// 上面代码没有问题，但是超出内存限制
// 优化：不再记录所有节点到root的路径，而是遍历 记录所有节点的father，然后向上遍历得到p q的路径

class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> parent;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, nullptr);
        unordered_set<TreeNode *> p_path;
        TreeNode *cur = p;
        while (cur != nullptr)
        {
            p_path.insert(cur);
            cur = parent[cur];
        }
        cur = q;
        while (cur != nullptr)
        {
            if (p_path.count(cur))
                return cur;
            cur = parent[cur];
        }
        return nullptr;
    }

    void dfs(TreeNode *node, TreeNode *father)
    {
        if (!node)
            return;
        parent[node] = father;
        dfs(node->left, node);
        dfs(node->right, node);
    }
};
// 下面是二叉树最近公共祖先LCA的递归最优解，核心是自底向上回溯

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base case：如果 root 是空，或就是 p 或 q，直接返回
        if (!root || root == p || root == q)
            return root;

        // 在左子树中找 p 或 q
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        // 在右子树中找 p 或 q
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 情况1：左右都找到 → 当前 root 就是最近公共祖先
        if (left && right)
            return root;

        // 情况2：只找到一个 → 把那个往上返回
        return left ? left : right;
    }
};