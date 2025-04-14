// 100618. 最小回文排列 I
// 给你一个 回文 字符串 s。

// 返回 s 的按字典序排列的 最小 回文排列。

// 如果一个字符串从前往后和从后往前读都相同，那么这个字符串是一个 回文 字符串。

// 排列 是字符串中所有字符的重排。

// 如果字符串 a 按字典序小于字符串 b，则表示在第一个不同的位置，a 中的字符比 b 中的对应字符在字母表中更靠前。
// 如果在前 min(a.length, b.length) 个字符中没有区别，则较短的字符串按字典序更小。
#include <bits/stdc++.h>
class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.size();
        if (s.size() <= 1)
        {
            return s;
        }
        int letter[26] = {0};
        for (char c : s)
        {
            letter[c - 'a'] += 1;
        }
        string result(n, '\0');
        int mid = n / 2;
        if (n % 2 == 1)
        {
            // 如果是奇数
            for (int i = 0; i < s.size(); i++)
            {
                if (letter[s[i] - 'a'] % 2 == 1)
                {
                    result[mid] = 'a' + i;
                    letter[i] --;
                    break;
                }
            }
            int index = 0;
            for (int i = 0; i < 26; i++)
            {
                while(letter[i] > 0){
                    result[index] = 'a'+i;
                    result[n - 1-index] = 'a' + i;
                    letter[i] -= 2;
                    index += 1;
                }
            }
        }
        return result;
    }
};