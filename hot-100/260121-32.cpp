// 32. 最长有效括号
// 困难

// 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号 子串 的长度。

// 左右括号匹配，即每个左括号都有对应的右括号将其闭合的字符串是格式正确的，比如 "(()())"。

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size(), result = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '('){
                st.push(i);
            }else{
                if(!st.empty()){
                    st.pop();
                    result += 1;
                }
            }
        }
        return result * 2;
    }
};

// 这个方法只能计算括号的数量，不能计算连续的有效长度

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size(), result = 0;
        if(n == 0 || n == 1)    return 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '(') st.push(i);
            else{
                if(!st.empty()){
                    s[i] = '0';
                    s[st.top()] = '0';
                    st.pop();
                }
            }            
        }
        // cout << s << endl;
        // 下一步计算连续最长的0
        vector<int> dp(n, 0);
        dp[0] = s[0] == '0' ? 1: 0;
        for (int i = 1; i < n; i++)
        {
            if(s[i] == '0'){
                dp[i] = dp[i-1] + 1;
            }
            result = max(result, dp[i]);
        }
        
        return result;
        
    }
};
