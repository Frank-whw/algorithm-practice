// 2942. 查找包含给定字符的单词
// 简单

// 提示
// 给你一个下标从 0 开始的字符串数组 words 和一个字符 x 。

// 请你返回一个 下标数组 ，表示下标在数组中对应的单词包含字符 x 。

// 注意 ，返回的数组可以是 任意 顺序。

#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> findWordsContaining(vector<string> &words, char x)
    {
        vector<int> res;
        for (int i = 0; i < words.size(); i++)
        {
            string str = words[i];
            for (char c : str)
            {
                if (c == x)
                {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};