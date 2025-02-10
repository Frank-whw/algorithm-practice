// 1049. 最后一块石头的重量 II
// 中等

// 提示
// 有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
// 每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。
// 那么粉碎的可能结果如下：

// 如果 x == y，那么两块石头都会被完全粉碎；
// 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
// 最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

int lastStoneWeightII(int* stones, int stonesSize) {
    int sum = 0;
    for(int i = 0; i < stonesSize; i++){
        sum += stones[i];
    }
    int weight = sum / 2;
    int* dp = malloc(sizeof(int) * (weight + 1));
    for(int i = 0; i <= weight; i++){
        dp[i] = 0;
    }
    for(int i = 0; i < stonesSize; i++){
        for(int j = weight; j >= stones[i]; j--){
            dp[j] = fmax(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return 2 * dp[weight] == sum ? 0 : sum -  2 * dp[weight];
}

// 不看题解没有思路
// 本题其实是尽量让石头分成重量相同的两堆（尽可能相同），相撞之后剩下的石头就是最小的
// 一堆的石头重量是sum，那么我们就尽可能拼成 重量为 sum / 2 的石头堆。 这样剩下的石头堆也是 尽可能接近 sum/2 的重量。 
// 那么此时问题就是有一堆石头，每个石头都有自己的重量，是否可以 装满 最大重量为 sum / 2的背包。

// 看了题解可以独立做出来