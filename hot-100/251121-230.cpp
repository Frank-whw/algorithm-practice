// 230. 二叉搜索树中第 K 小的元素


// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，
// 请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        scan(root, arr);
        return arr[k - 1];
    }
    void scan(TreeNode* root, vector<int> &arr){
        if(root == NULL) return;
        scan(root->left, arr);
        arr.push_back(root->val);
        cout << root->val << endl;
        scan(root->right, arr);
    }
};