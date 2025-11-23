// 105. 从前序与中序遍历序列构造二叉树

// 中等
// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， 
// inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。


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
    unordered_map<int, int> ii; // inorder_index
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            ii[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* buildTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if(pe <= ps || ie <= is )    return nullptr;
        TreeNode* node = new TreeNode(preorder[ps]);
        if (pe - ps == 1 && ie - is == 1)   return node;
        int index = ii[preorder[ps]];
        node->left = buildTree(preorder, ps + 1, ps + index - is + 1, inorder, is, index);
        node->right = buildTree(preorder, ps + index - is + 1, pe, inorder, index + 1, ie);
        return node;
    }
};

// 分治+哈希
// 不难