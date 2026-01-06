// 45. 跳跃游戏 II
// 中等

// 给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。

// 每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，
// 你可以跳转到任意 (i + j) 处：

// 0 <= j <= nums[i] 且
// i + j < n
// 返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> minStep(n, INT_MAX);
        minStep[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= nums[i] && i + j < n; j++){
                minStep[i + j] = min(minStep[i] + 1, minStep[i + j]);
            }
        }
        return minStep[n - 1];
    }
};
// 暴力 用一个数组记录每个位置的最少步数


// 反向查找出发位置
// 反复 从前往后找 离position最远的点
class Solution {
public:
    int jump(vector<int>& nums) {
        int position = nums.size() - 1;
        int step = 0;
        while (position > 0)
        {
            for(int i = 0; i < position; i++){
                if(i + nums[i] >= position){
                    position = i;
                    step++;
                    break;
                }
            }
        }
        return step;
        
        
    }
};

// 正向查找可到达的最大位置
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int right = 0, step = 0, maxPosition = 0;
        for(int i = 0; i < n - 1; i++){
            maxPosition = max(maxPosition, i + nums[i]);
            if(i == right){
                right = maxPosition;
                step++;
            }
        }
        return step;
    }
};