// 134. 加油站
// 中等

// 在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
// 你从其中的一个加油站出发，开始时油箱为空。

// 给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，
// 则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalOil = 0;  // 记录总油量和总消耗的差值
    int currentOil = 0; // 记录从当前出发加油站开始的剩余油量
    int start = 0;  // 记录可能的出发加油站编号

    for (int i = 0; i < gasSize; i++) {
        totalOil += gas[i] - cost[i];
        currentOil += gas[i] - cost[i];
        // 如果当前剩余油量小于 0，说明从 start 出发无法到达 i+1 加油站
        if (currentOil < 0) {
            start = i + 1;  // 更新出发加油站为 i+1
            currentOil = 0; // 重置当前剩余油量
        }
    }
    // 如果总油量和总消耗的差值小于 0，说明无法绕环路一周
    if (totalOil < 0) {
        return -1;
    }
    return start;
}

// 本题我不认为是贪心算法
// 题目理解不难，但是第一次做的时候被绕住了
