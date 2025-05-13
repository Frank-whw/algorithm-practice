// 3335. 字符串转换后的长度 I
// 中等

// 提示
// 给你一个字符串 s 和一个整数 t，表示要执行的 转换 次数。每次 转换 需要根据以下规则替换字符串 s 中的每个字符：

// 如果字符是 'z'，则将其替换为字符串 "ab"。
// 否则，将其替换为字母表中的下一个字符。例如，'a' 替换为 'b'，'b' 替换为 'c'，依此类推。
// 返回 恰好 执行 t 次转换后得到的字符串的 长度。

// 由于答案可能非常大，返回其对 109 + 7 取余的结果。

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {
        const int MOD = 1e9 + 7;
        int res = 0;
        vector<int> freq(26, 0);
        for (char c : s)
        {
            freq[c - 'a'] += 1;
        }
        while (t--)
        {
            int z = freq[25] % MOD;
            for (int i = 25; i >= 1; i--)
            {
                freq[i] = freq[i - 1] % MOD;
            }
            freq[0] = z;
            freq[1] += z;
            freq[1] %= MOD;
        }
        for (int i : freq)
        {
            res = (res + i) % MOD;
        }
        return res;
    }
};

// 硬模拟
// 一开始以为有什么比较高级的方法，没找到