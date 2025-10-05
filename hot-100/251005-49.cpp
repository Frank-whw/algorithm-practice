// 49. 字母异位词分组
// 中等

// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        // key是排序后的string，value是原始string
        unordered_map<string, vector<string>> mp;
        for(string str : strs){
            string key = str;
            // 排序 确保唯一性
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        // auto it迭代器
        for(auto it = mp.begin(); it != mp.end(); ++it){
            res.push_back(it->second);
        }
        return res;
    }
};