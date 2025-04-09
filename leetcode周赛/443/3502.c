// 3502. 到达每个位置的最小费用
// 简单

// 提示
// 给你一个长度为 n 的整数数组 cost 。当前你位于位置 n（队伍的末尾），队伍中共有 n + 1 人，编号从 0 到 n 。

// 你希望在队伍中向前移动，但队伍中每个人都会收取一定的费用才能与你 交换位置。与编号 i 的人交换位置的费用为 cost[i] 。

// 你可以按照以下规则与他人交换位置：

// 如果对方在你前面，你 必须 支付 cost[i] 费用与他们交换位置。
// 如果对方在你后面，他们可以免费与你交换位置。
// 返回一个大小为 n 的数组 answer，其中 answer[i] 表示到达队伍中每个位置 i 所需的 最小 总费用。

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* minCosts(int* cost, int costSize, int* returnSize) {
    int* result = malloc(sizeof(int) * costSize);
    int minIndex  = 0;
    result[0] = cost[0];
    for(int i = 1; i < costSize; i++){
        if(cost[i] < cost[minIndex]){
            minIndex = i;
        }
        result[i] = cost[minIndex];
    }
    *returnSize = costSize;
    return result;
}

// 很简单
// 5min做出来
