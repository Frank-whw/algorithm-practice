// 739. 每日温度

// 中等

// 给定一个整数数组 temperatures ，表示每天的温度，
// 返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
// 如果气温在这之后都不会升高，请在该位置用 0 来代替。

#include <bits/stdc++.h>
using namespace std;

// 2重循环 暴力
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (temperatures[j] > temperatures[i])
                {
                    answer[i] = j - i;
                    break;
                }
            }
        }
        return answer;
    }
};

// 单调栈
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};