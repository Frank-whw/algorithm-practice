// 560. 和为 K 的子数组

// 中等

// 提示
// 给你一个整数数组 nums 和一个整数 k ，
// 请你统计并返回 该数组中和为 k 的子数组的个数 。

// 子数组是数组中元素的连续非空序列。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0, n = nums.size();
        vector<int> count;
        count.push_back(0);
        count.push_back(nums[0]);
        for (int i = 2; i < n + 1; i++)
        {
            count.push_back(nums[i - 1] + count[i - 1]);
        }
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = i + 1; j < n + 1; j++)
            {
                // key 表示[i+1, j]的和
                int key = count[j] - count[i];
                if (key == k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// pre[i]=pre[i−1]+nums[i]
// 以上我单纯只用了 前缀和 完成 

// 最优解是 前缀和 + 哈希
// pre[j−1]==pre[i]−k
// 所以我们考虑以 i 结尾的和为 k 的连续子数组个数时只要统计有多少个前缀和为 pre[i]−k 的 pre[j] 即可。
// 我们建立哈希表 mp，以和为键，出现次数为对应的值，记录 pre[i] 出现的次数，
// 从左往右边更新 mp 边计算答案，那么以 i 结尾的答案 mp[pre[i]−k] 即可在 O(1) 时间内得到。
// 最后的答案即为所有下标结尾的和为 k 的子数组个数之和。



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for(auto& x : nums){
            pre += x;
            if(mp.find(pre-k) != mp.end()){
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};