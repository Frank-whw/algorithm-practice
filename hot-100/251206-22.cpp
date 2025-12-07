// 22. 括号生成

// 中等
// 数字 n 代表生成括号的对数，请你设计一个函数，
// 用于能够生成所有可能的并且 有效的 括号组合。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<string> result;
    string combination;
    bool isValid(string &com)
    {
        stack<char> s;
        for (int i = 0; i < com.size(); i++)
        {
            if (com[i] == '(')
            {
                s.push('(');
            }
            else if (com[i] == ')')
            {
                if (s.empty())
                    return false;
                char c = s.top();
                s.pop();
                if (c != '(')
                {
                    return false;
                }
            }
        }
        return true;
    }
    void backTrack(int n, int num1, int num2)
    {
        if (num1 > n || num2 > num1)
        // 一开始是num2 > n，但是后面发现如果当前字符串左括号的数量少于右括号 那么肯定不满足
            return;
        if (num1 == n && num2 == n)
        {
            if (isValid(combination))
            {
                result.push_back(combination);
            }
            return;
        }
        combination.push_back('(');
        backTrack(n, num1 + 1, num2);
        combination.pop_back();
        combination.push_back(')');
        backTrack(n, num1, num2 + 1);
        combination.pop_back();
    }

public:
    vector<string> generateParenthesis(int n)
    {
        backTrack(n, 0, 0);
        return result;
    }
};
// 暴力穷举

// 优化：不需要isValid
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<string> result;
    string combination;
    void backTrack(int n, int num1, int num2)
    {
        if (num1 > n || num2 > num1)
            return;
        if (num1 == n && num2 == n)
        {
            result.push_back(combination);
            return;
        }
        combination.push_back('(');
        backTrack(n, num1 + 1, num2);
        combination.pop_back();
        combination.push_back(')');
        backTrack(n, num1, num2 + 1);
        combination.pop_back();
    }

public:
    vector<string> generateParenthesis(int n)
    {
        backTrack(n, 0, 0);
        return result;
    }
};