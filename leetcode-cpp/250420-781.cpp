// 781. 森林中的兔子
// 中等

// 森林中有未知数量的兔子。提问其中若干只兔子
// "还有多少只兔子与你（指被提问的兔子）颜色相同?" ，
// 将答案收集到一个整数数组 answers 中，
// 其中 answers[i] 是第 i 只兔子的回答。

// 给你数组 answers ，返回森林中兔子的最少数量。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        sort(answers.begin(), answers.end());
        int count = 0;
        for (int i = 0; i < answers.size(); i++)
        {
            int answer = answers[i];
            if (answer == 0)
            {
                count += 1;
            }
            else
            {
                count += answers[i] + 1;
                int index = answers[i] + i;
                while (i < answers.size() - 1 && i < index && answers[i + 1] == answers[i])
                    i++;
            }
        }
        return count;
    }
};
// 不用哈希，空间O(1)解法
// 每只兔子回答 answers[i] 表示还有 answers[i] 只与它颜色相同的兔子，因此这类兔子的总数是 answers[i] + 1（包括它自己）。
// 具有相同回答 answers[i] 的兔子可以组成一组，每组最多包含 answers[i] + 1 只兔子，且这些兔子的回答必须完全一致。

// 我们先对 answers 数组进行排序，使相同回答的兔子聚集在一起。
// 接着从前往后遍历数组，以当前的 answers[i] 为基准，尝试将相同回答的兔子尽量填入一组（每组至多 answers[i] + 1 只）。
// 每形成一组，就将该组的兔子总数计入结果中。