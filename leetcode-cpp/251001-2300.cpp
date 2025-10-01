// 2300. 咒语和药水的成功对数
// 中等

// 提示
// 给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，
// 其中 spells[i] 表示第 i 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。

// 同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，
// 那么它们视为一对 成功 的组合。

// 请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        int n = potions.size();
        sort(potions.begin(), potions.end());
        for(int s : spells){
            // long long key = success / s; 作为阈值会偏小，需要向上取整
            long long key = (success + s - 1) / s;
            int left = 0, right = n - 1;
            while(left < right){
                int mid = left + (right - left) / 2;
                // cout << left << "  " << mid << " " << right << endl;
                if(potions[mid] < key){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            // 判断找到的位置是否满足条件
            if(potions[left] >= key){
                res.push_back(n - left);
            }else{
                res.push_back(0); 
            }
        }
        return res;
    }
};

// better solution
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto& i : spells) {
            long long t = (success + i - 1) / i - 1;
            res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
        }
        return res;
    }
};


// upper_bound 
// 在已经排序的序列中快速查找第一个大二目标值的元素位置，本质是二分查找
// 返回迭代器指向序列中第一个大于 value 的元素

// upper_bound(起始位置，末位，value)


