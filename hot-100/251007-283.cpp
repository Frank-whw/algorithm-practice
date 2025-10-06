// 283. 移动零
// 简单
// 提示
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void swap(int *a, int *b){
        int t = *a;
        *a = *b;
        *b = t;
    }
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 1;
        while(left < nums.size() && right < nums.size()){
            // 如果left指向0
            if(!nums[left]){
                right = left;
                // right找到第一个非0元素
                while(!nums[right]){
                    right++;
                    if(right == nums.size()){
                        return;
                    }
                }
                // 交换
                swap(&nums[left], &nums[right]);
                left++;
                right++;
            }else{
                left++;
            }
        }
    }
};

// 代码写的很恶心
// 官方题解

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
// 1.left左边均非零
// 2.right左边直到left均为0

