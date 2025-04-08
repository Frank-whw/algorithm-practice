// 968. 监控二叉树
// 困难

// 给定一个二叉树，我们在树的节点上安装摄像头。
// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
// 计算监控树的所有节点所需的最小摄像头数量。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
**函数后序遍历二叉树。判断一个结点状态时，根据其左右孩子结点的状态进行判断
**状态：0为没有被摄像头覆盖到。1为此结点处应设置摄像头。2为此结点已被摄像头覆盖
*/
int traversal(struct TreeNode* node, int* ans) {
    //递归结束条件：传入结点为NULL，假设此结点能被摄像头覆盖。这样方便与对叶子结点的判断，将叶子结点设为0
    if(!node)
        return 2;
    //后序遍历二叉树，记录左右孩子的状态。根据左右孩子状态更新结点自身状态
    int left = traversal(node->left, ans);
    int right = traversal(node->right, ans);

    //若左右孩子都可以被摄像头覆盖，将父亲结点状态设为0
    if(left == 2 && right == 2) {
        return 0;
    }
    //若左右孩子有一个结点状态为没有被覆盖（0），则将父亲结点状态设置为摄像头
    if(left == 0 || right == 0) {
        (*ans)++;
        return 1;
    }
    //若左右孩子有一个为摄像头，证明父亲结点可以被覆盖。将父亲结点状态变为2
    if(left == 1 || right == 1)
        return 2;
    //逻辑不会走到-1，语句不会执行
    return -1;
}

int minCameraCover(struct TreeNode* root){
    int ans = 0;

    //在对整个二叉树遍历后。头结点可能未被覆盖，这时候如果函数返回值为0，证明头结点未被覆盖。说明头结点也需要添置摄像头，ans++
    if(traversal(root, &ans) == 0)
        ans++;
    return ans;
}
