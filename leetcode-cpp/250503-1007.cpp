// 1007. 行相等的最少多米诺旋转
// 中等

// 在一排多米诺骨牌中，tops[i] 和 bottoms[i] 分别代表第 i 个多米诺骨牌的上半部分和下半部分。（一个多米诺是两个从 1 到 6 的数字同列平铺形成的 —— 该平铺的每一半上都有一个数字。）

// 我们可以旋转第 i 张多米诺，使得 tops[i] 和 bottoms[i] 的值交换。

// 返回能使 tops 中所有值或者 bottoms 中所有值都相同的最小旋转次数。

// 如果无法做到，返回 -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int check(int x, vector<int> &A, vector<int> &B, int n)
    {
        int rotation_a = 0, rotation_b = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] != x && B[i] != x)
                return -1;
            else if (A[i] != x)
            {
                rotation_a += 1;
            }
            else if(B[i] != x)
            {
                rotation_b += 1;
            }
        }
        return min(rotation_a, rotation_b);
    }
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int n = tops.size();
        int rotation = check(tops[0], bottoms, tops, n);
        if (rotation != -1 || tops[0] == bottoms[0])
            return rotation;
        else
            return check(bottoms[0], bottoms, tops, n);
    }
};

// 这道题有点难理解
// 官方题解用的是 贪心
// 核心思路是 如果有解，就必须存在一块多米诺骨牌，它的2个数字x在所有其它的多米诺骨牌中都出现过
// 所以我们只需要选取任意一块，对其调用2次check函数

// check函数接受x，返回转a和转b的最小次数

// 为什么rotation != -1的时候直接返回rotation？
// 因为如果x设置为bottoms[0]也有解的话，整个多米诺骨牌一定是呈现对称的情况
// eg:121111 & 212222