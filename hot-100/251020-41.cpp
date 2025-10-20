// 41. 缺失的第一个正数
// 困难

// 提示
// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set;
        int minNum = INT_MAX;
        for(int num : nums){
            if(num > 0){
                minNum = num < minNum ? num : minNum;
                set.insert(num);
            }
        }
        if(minNum != 1){
            return 1;
        }
        for(int i = 2; ;i++){
            if(set.count(i) == 0){
                return i;
            }
        }
    }
};

// 一遍过

