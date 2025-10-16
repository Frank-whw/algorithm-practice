// 76. 最小覆盖子串

// 困难

// 提示
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int sSize = s.size(), tSize = t.size();
        if (s == t)
            return s;
        if (sSize < tSize)
            return "";
        vector<int> sCount(126, 0);
        vector<int> tCount(126, 0);
        unordered_set<char> set;
        for (char c : t)
        {
            set.insert(c);
            tCount[c]++;
        }
        int required = set.size();
        int formed = 0;
        int l = 0, r = 0;
        int minLen = INT_MAX;
        int start = 0, end = 0;
        while (r < sSize)
        {
            char c = s[r];
            if (set.count(c))
            {
                sCount[c]++;
                if (sCount[c] == tCount[c])
                {
                    formed++;
                }
            }
            while (l <= r && formed == required)
            {
                c = s[l];
                int curLen = r - l + 1;
                if (curLen < minLen)
                {
                    minLen = curLen;
                    start = l;
                    end = r;
                }
                if (set.count(c))
                {
                    sCount[c]--;
                    if (sCount[c] < tCount[c])
                    {
                        formed--;
                    }
                }
                l++;
            }
            r++;
        }
    }
};