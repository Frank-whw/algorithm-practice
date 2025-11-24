// 437. 路径总和 III

// 中等

// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

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
    int pathSum(TreeNode *root, int targetSum)
    {
        return pathSum(root, targetSum, 0);
    }
    int pathSum(TreeNode *root, long long targetSum, bool isStarted)
    {
        if (root == nullptr)
            return 0;
        int result = 0;
        if(root->val == targetSum){
            result += 1;
        }
        if (!isStarted)
        {
            result += pathSum(root->left, targetSum, 0);
            result += pathSum(root->right, targetSum, 0);
        }
        result += pathSum(root->left, targetSum - root->val, 1);
        result += pathSum(root->right, targetSum - root->val, 1);

        return result;
    }
};

// 思路是对的 但是runtime error
// 后面发现把int pathSum(TreeNode *root, int targetSum, bool isStarted)
//      改为int pathSum(TreeNode *root, long long targetSum, bool isStarted)就可以了

// 引入isStarted的想法是 担心有路径不连续但是和是target。本质是 单函数融合双重递归
// 下面给出双重递归的解法：

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        // 1. 以当前节点为起点的路径数
        // 2. 左子树中所有满足条件的路径数（递归找左子树的起点）
        // 3. 右子树中所有满足条件的路径数（递归找右子树的起点）
        return countFromRoot(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
private:
    // 从root出发（必须包含root），向下找和为target的路径数
    int countFromRoot(TreeNode* root, long long target) {
        if (!root) return 0;
        int res = 0;
        // 当前节点值等于剩余target，计数+1（可能是单节点路径）
        if (root->val == target) res++;
        // 递归左右子树：剩余target减去当前节点值，继续向下找
        res += countFromRoot(root->left, target - root->val);
        res += countFromRoot(root->right, target - root->val);
        return res;
    }
};

// 双重递归的时间复杂度是O(N^2)

// 最优解是前缀和，减少重复计算 ：由根结点到当前结点的路径上所有节点的和

class Solution {
public:
    // 前缀和哈希表：key = 从根节点到某节点的路径累加和（前缀和），value = 该前缀和出现的次数
    // 作用：快速查询「当前前缀和 - targetSum」是否存在，存在则说明有路径和为targetSum
    unordered_map<long long, int> prefix;

    int pathSum(TreeNode* root, int targetSum) {
        // 初始化：前缀和为0的路径出现1次（关键！对应「从根节点到当前节点的前缀和刚好等于targetSum」的情况）
        // 例：若当前前缀和curr=targetSum，则curr-targetSum=0，此时需统计这1条路径（根→当前节点）
        prefix[0] = 1;
        // 启动DFS：初始前缀和为0（还未遍历任何节点），目标和为targetSum
        return dfs(root, 0, targetSum);
    }

    // DFS函数：递归遍历节点，计算前缀和并统计有效路径数
    // root：当前正在遍历的节点
    // curr：从根节点到「当前节点的父节点」的前缀和（进入函数后会加上当前节点值，更新为到当前节点的前缀和）
    // targetSum：题目要求的目标和
    // 返回值：以当前节点为「路径终点」的所有有效路径数
    int dfs(TreeNode* root, long long curr, int targetSum) {
        // 递归终止条件：当前节点为空，无有效路径，返回0
        if (!root) return 0;

        int ret = 0; // 存储以当前节点为终点的有效路径数

        // 步骤1：更新前缀和——加上当前节点的值，得到「根→当前节点」的前缀和
        curr += root->val;

        // 步骤2：核心逻辑——查询是否存在「当前前缀和 - targetSum」的前缀和
        // 原理：若存在前缀和sum_prev = curr - targetSum，则「sum_prev对应的节点的下一个节点 → 当前节点」的路径和 = targetSum
        // 例如：sum_prev（根→A）= 3，curr（根→B）= 8，target=5 → 8-5=3，说明A→B的路径和=5，有效
        if (prefix.count(curr - targetSum)) {
            ret = prefix[curr - targetSum]; // 有效路径数 = 该前缀和出现的次数（可能有多个节点的前缀和为sum_prev）
        }

        // 步骤3：将当前前缀和加入哈希表，供其左右子树查询（标记当前路径上存在该前缀和）
        prefix[curr]++;

        // 步骤4：递归遍历左右子树，累加左右子树中以它们的节点为终点的有效路径数
        // 注意：此时curr已更新为「根→当前节点」的前缀和，传给子树后会继续累加子节点值
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);

        // 步骤5：回溯——撤销当前前缀和的计数（关键！避免影响其他路径）
        // 原因：DFS是深度优先，遍历完当前节点的左右子树后，要回到父节点，当前节点的前缀和不应出现在父节点的其他子树路径中
        // 例如：当前节点是左子节点，遍历完后要去右子节点，此时需删除当前节点的前缀和，防止右子树误判路径
        prefix[curr]--;

        // 返回以当前节点为终点的有效路径数，供父节点累加
        return ret;
    }
};