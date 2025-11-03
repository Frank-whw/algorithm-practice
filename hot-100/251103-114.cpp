// 114. 二叉树展开为链表

// 给你二叉树的根结点 root ，请你将它展开为一个单链表：

// 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，
// 而左子指针始终为 null 。
// 展开后的单链表应该与二叉树 先序遍历 顺序相同。

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
    // 递归处理以root为根的子树，返回展开后链表的尾节点
    TreeNode* flattenHelper(TreeNode* root) {
        if (root == nullptr) return nullptr; // 空节点，无尾节点
        
        // 叶子节点：尾节点是自身
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        
        // 递归处理左右子树，获取尾节点
        TreeNode* leftTail = flattenHelper(root->left);
        TreeNode* rightTail = flattenHelper(root->right);
        
        // 若左子树存在，需连接左子树尾和右子树头
        if (leftTail != nullptr) {
            leftTail->right = root->right; // 左子树尾 -> 右子树头
            root->right = root->left;      // 根的右指针 -> 左子树头
            root->left = nullptr;          // 左指针置空
        }
        
        // 确定当前子树的尾节点：右子树尾存在则用它，否则用左子树尾
        return rightTail != nullptr ? rightTail : leftTail;
    }
    void flatten(TreeNode *root)
    {
        flattenHelper(root);
    }
};