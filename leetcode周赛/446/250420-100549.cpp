// 100549. 执行指令后的得分
// 给你两个数组：instructions 和 values，数组的长度均为 n。

// 你需要根据以下规则模拟一个过程：

// 从下标 i = 0 的第一个指令开始，初始得分为 0。
// 如果 instructions[i] 是 "add"：
// 将 values[i] 加到你的得分中。
// 移动到下一个指令 (i + 1)。
// 如果 instructions[i] 是 "jump"：
// 移动到下标为 (i + values[i]) 的指令，但不修改你的得分。
// 当以下任一情况发生时，过程会终止：

// 越界（即 i < 0 或 i >= n），或
// 尝试再次执行已经执行过的指令。被重复访问的指令不会再次执行。
// 返回过程结束时的得分。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long calculateScore(vector<string> &instructions, vector<int> &values)
    {
        using ll = long long;
        ll score = 0;
        int n = instructions.size();
        vector<bool> hasInvited(n, false);
        int index = 0;
        while (index >= 0 && index < n && hasInvited[index] != true)
        {
            if (instructions[index] == "jump")
            {
                hasInvited[index] = true;
                index = index + values[index];
            }
            else if (instructions[index] == "add")
            {
                hasInvited[index] = true;
                score += values[index];
                index += 1;
            }
        }
        return score;
    }
};