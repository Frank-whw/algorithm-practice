// 1128. 等价多米诺骨牌对的数量
// 简单

// 提示
// 给你一组多米诺骨牌 dominoes 。

// 形式上，dominoes[i] = [a, b] 与 dominoes[j] = [c, d] 等价
// 当且仅当 (a == c 且 b == d) 或者 (a == d 且 b == c) 。
// 即一张骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌。

// 在 0 <= i < j < dominoes.length 的前提下，
// 找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对 (i, j) 的数量。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        vector<int> num(100);
        int ret = 0;
        for (auto &it : dominoes)
        {
            int val = it[0] < it[1] ? it[0] * 10 + it[1] : it[1] * 10 + it[0];
            ret += num[val];
            num[val]++;
        }
        return ret;
    }
};

// 本题中我们需要统计所有等价的多米诺骨牌，其中多米诺骨牌使用二元对代表，
// 「等价」的定义是，在允许翻转两个二元对的的情况下，使它们的元素一一对应相等。

// 于是我们不妨直接让每一个二元对都变为指定的格式，即第一维必须不大于第二维。
// 这样两个二元对「等价」当且仅当两个二元对完全相同。

// 注意到二元对中的元素均不大于 9，因此我们可以将每一个二元对拼接成一个两位的正整数，
//  (x,y)→10x+y。这样就无需使用哈希表统计元素数量，而直接使用长度为 100 的数组即可。
