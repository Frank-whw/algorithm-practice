// 169. 多数元素
// 简单
// lock icon
// 相关企业
// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。
// 多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto t : nums){
            if(map.find(t) != map.end()){
                map[t] += 1;
            }else{
                map[t] = 1;
            }
        }
        int result = nums[0];
        for(auto m : map){
            if(m.second > map[result]){
                result = m.first;
            }
        }
        return result;
    }
};

// 写的不够简洁
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int result = 0, cnt = 0;
        for(int num : nums){
            counts[num]++;
            if(counts[num] > cnt){
                result = num;
                cnt = counts[num];
            }
        }
        return result;
    }
};


// 根据题目中 “出现次数 大于 ⌊ n/2 ⌋ 的元素”，
// 如果将数组 nums 中的所有元素按照单调递增或单调递减的顺序排序，那么 中间的数就是result
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
