// 17. 电话号码的字母组合

// 中等

// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    unordered_map<int, string> map = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}};
    vector<string> result;
    string str;
    void backTrack(string digits, int start)
    {
        if (str.size() == digits.size())
        {
            result.push_back(str);
            return;
        }
        int ch = digits[start] - '0';
        string letters = map[ch];
        for (char c : letters)
        {
            str.push_back(c);
            backTrack(digits, start + 1);
            str.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        for (int i = 0; i < digits.size(); i++)
        {
            int ch = digits[i] - '0';
            string letters = map[ch];
            for (char c : letters)
            {
                str.push_back(c);
                backTrack(digits, i + 1);
                str.pop_back();
            }
        }
        return result;
    }
};

// 不是最优
// 其中map的使用没有必要，可以用vector<string> index = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};替代
// 优化后：
class Solution
{
private:
    vector<string> index = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string str;
    void backTrack(string digits, int start)
    {
        if (str.size() == digits.size())
        {
            result.push_back(str);
            return;
        }
        int ch = digits[start] - '0';
        string letters = index[ch];
        for (char c : letters)
        {
            str.push_back(c);
            backTrack(digits, start + 1);
            str.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        backTrack(digits, 0);
        return result;
    }
};