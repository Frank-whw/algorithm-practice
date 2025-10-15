// 76. 最小覆盖子串

// 困难

// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
        {
            return "";
        }
        else if (s == t)
        {
            return t;
        }
        vector<int> tCount(128, 0);
        vector<int> sCount(128, 0);
        unordered_set<char> set;
        for (char c : t)
        {
            set.insert(c);
            tCount[c] += 1;
        }
        int required = set.size();  // 需要满足的不同字符数量
        int formed = 0;                     // 当前窗口中已满足的字符数量

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0, end = 0;
        while (right < s.size())
        {
            char c = s[right];
            if (set.count(c))
            {
                sCount[c]++;
                if(sCount[c] == tCount[c]){
                    formed++;
                }
            }
            // 当窗口已包含所有必要字符时，尝试收缩左边界
            while (left <= right && formed == required)
            {
                c = s[left];
                // 更新最小窗口
                int currentLen = right - left + 1;
                if (currentLen < minLen)
                {
                    minLen = currentLen;
                    start = left;
                    end = right;
                }
                
                // 移动左指针，缩小窗口
                if (set.count(c))
                {
                    sCount[c]--;
                    // 如果某个字符数量不再满足需求，减少已满足计数
                    if (sCount[c] < tCount[c])
                    {
                        formed--;
                    }
                }
                left++;
            }
            
            right++;
        }
        
        // 如果没有找到有效窗口，返回空字符串
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};