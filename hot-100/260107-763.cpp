// 763. 划分字母区间

// 中等

// 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
// 例如，字符串 "ababcc" 能够被分为 ["abab", "cc"]，
// 但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。

// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

// 返回一个表示每个字符串片段的长度的列表。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < s.size(); i++)
        {
            if(map.find(s[i]) == map.end()){
                map[s[i]] = {i,i};
            }else{
                map[s[i]].second = i;
            }
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(map[s[i]].second, right);
            if(i == right){
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return result;
    }
};

// 使用 哈希表 记录了每个字母的 首次出现和最后一次出现 的位置
// 但其实不用记录首次出现的位置
// 最优解：

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastPosition(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            lastPosition[s[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            right = max(right, lastPosition[s[i] - 'a']);
            if(i == right){
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return result;
        
    }
};