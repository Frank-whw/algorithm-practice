// 347. 前 K 个高频元素
// 中等

// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。
// 你可以按 任意顺序 返回答案。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void qsort(vector<pair<int,int>>& v, int start, int end, vector<int>& ret, int k){
        int picked = rand() % (end - start + 1) + start;
        swap(v[picked], v[start]);
        int pivot = v[start].second;
        int index = start;
        for (int i = start; i <= end; i++)
        {
            if(v[i].second >= pivot){
                swap(v[index + 1], v[i]);
                index++;
            }
        }
        swap(v[start], v[index]);
        if(k <= index - start){
            qsort(v, start, index - 1, ret, k);
        }else{
            for(int i = start; i <= index; i++){
                ret.push_back(v[i].first);
            }
            if(k > index - start + 1){
                qsort(v, index + 1, end, ret, k - (index - start + 1));
            }
        }
        
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurances;
        for(auto& v : nums){
            occurances[v]++;
        }
        vector<pair<int,int>> values;
        for(auto& kv: occurances){
            values.push_back(kv);
        }
        vector<int> ret;
        qsort(values, 0, values.size(), ret, k);
        return ret;
    }
};