// 20. 有效的括号

// 简单

// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty()) return false;
                char t = st.top();
                st.pop();
                if (t == '(' && c == ')' || t == '{' && c == '}' || t == '[' && c == ']')
                {
                    continue;
                }
                else
                    return false;
            }
        }
        return st.empty();
    }
};