// 3. 无重复字符的最长子串

// 中等

// 提示
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0, r = 0, n = s.size(), cur = 0;
        unordered_map<int, int> map;
        while(r < n){
            map[s[r]]++;
            if(map[s[r]] == 1){
                r++;
                cur++;
                ans = max(ans, cur);
            }else{
                while(map[s[r]] > 1 && l < r){
                    map[s[l]]--;
                    l++;
                    cur--;
                }
                r++;
                cur++;
            }
        }
        return ans;
    }
};


// 滑动窗口
// 感觉代码不够清晰
// 如果 r 是新字符串，cur ++
// 否则把 l 移到重复位置的下一位


// 改进:用一个 lastPos 数组记录 c 最后一次出现的位置 p，且 p >= l
// 然后直接令 l = p +  1 即可，避免遍历
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastPos;
        int ans = 0, l = 0;
        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            if(lastPos.find(c) != lastPos.end() && lastPos[c] >= l){
                l = lastPos[c] + 1;
            }
            lastPos[c] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};