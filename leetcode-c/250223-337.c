// 337. 打家劫舍 III
// 中等

// 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
// 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。
// 一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
// 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

// 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int* robTree(struct TreeNode* node){
    int* amounts = malloc(sizeof(int) * 2);
    memset(amounts, 0, sizeof(int) * 2);
    if(node == NULL){
        return amounts;
    }
    int* left = robTree(node->left);
    int* right = robTree(node->right);
    // 偷当前节点
    amounts[1] = node->val + left[0] + right[0];
    // 不偷当前节点
    amounts[0] = fmax(left[0], left[1]) + fmax(right[0], right[1]);
    return amounts;
}
int rob(struct TreeNode* root) {
    int* dp = robTree(root);
    return max(dp[0], dp[1]);
}