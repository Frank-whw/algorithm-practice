// 438. 找到字符串中所有字母异位词

// 中等

// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，
// 返回这些子串的起始索引。不考虑答案输出的顺序。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sSize = s.size(), pSize = p.size();
        if(sSize < pSize){
            return vector<int>();
        }
        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for(int i = 0; i < pSize; i++){
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }
        if(sCount == pCount){
            ans.push_back(0);
        }
        for(int i = 0; i + pSize< sSize ; i++){
            sCount[s[i] - 'a']--;
            sCount[s[i + pSize] - 'a']++;
            if(sCount == pCount){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

// 一开始想的太复杂，如果新加入的s[r]不在p中，窗口直接瞬移到 r 的右侧
// 对于这种滑动窗口的题，还是老老实实平移好了，尤其是 定长窗口