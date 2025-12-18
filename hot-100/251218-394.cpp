// 394. 字符串解码

// 中等

// 给定一个经过编码的字符串，返回它解码后的字符串。

// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。
// 注意 k 保证为正整数。

// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

// 测试用例保证输出的长度不会超过 105。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    stack<char> sk;
    int getTimes()
    {
        string s2 = "";
        while (!sk.empty() && sk.top() >= '0' && sk.top() <= '9')
        {
            s2 += sk.top();
            sk.pop();
        }
        reverse(s2.begin(), s2.end());

        return stoi(s2);
    }
    string getS1()
    {
        string s1 = "";
        while (sk.top() != '[')
        {
            s1 += sk.top();
            sk.pop();
        }
        sk.pop(); // 弹出 [
        reverse(s1.begin(), s1.end());
        return s1;
    }
    void pushXs1(string s1, int times)
    {
        for (int i = 0; i < times; i++)
        {
            for (char c : s1)
            {
                sk.push(c);
            }
        }
    }

public:
    string decodeString(string s)
    {
        string result = "";

        for (char c : s)
        {

            if (c == ']')
            {
                string s1 = getS1();
                int times = getTimes();
                pushXs1(s1, times);
            }
            else
            {
                sk.push(c);
            }
        }
        while (!sk.empty())
        {
            result += sk.top();
            sk.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// 豆包的优化解法


class Solution {
public:
    string decodeString(string s) {
        // 栈存储：<当前层的前缀字符串, 该层的重复次数>
        stack<pair<string, int>> stk;
        string current_str;  // 当前正在构建的字符串
        int current_num = 0; // 当前累积的数字
        
        for (char c : s) {
            if (isdigit(c)) {
                // 直接计算数字，避免字符串拼接后转整数
                current_num = current_num * 10 + (c - '0');
            } else if (c == '[') {
                // 遇到左括号，将当前字符串和数字入栈，重置临时变量
                stk.emplace(current_str, current_num);
                current_str.clear();
                current_num = 0;
            } else if (c == ']') {
                // 遇到右括号，弹出栈顶的前缀和次数，拼接重复后的字符串
                auto [prev_str, times] = stk.top();
                stk.pop();
                // 构建重复后的字符串：前缀 + 当前字符串重复times次
                string repeated;
                repeated.reserve(prev_str.size() + current_str.size() * times); // 预分配空间，减少扩容
                repeated += prev_str;
                for (int i = 0; i < times; ++i) {
                    repeated += current_str;
                }
                current_str = move(repeated); // 移动语义，避免拷贝
            } else {
                // 普通字符，直接追加到当前字符串
                current_str.push_back(c);
            }
        }
        return current_str;
    }
};