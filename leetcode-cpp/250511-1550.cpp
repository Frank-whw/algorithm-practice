// 1550. 存在连续三个奇数的数组
// 简单

// 提示
// 给你一个整数数组 arr，请你判断数组中是否存在连续三个元素都是奇数的情况：
// 如果存在，请返回 true ；否则，返回 false 。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOdd(vector<int> &arr, int i)
    {
        return arr[i] % 2 == 1 ? true : false;
    }
    bool threeConsecutiveOdds(vector<int> &arr)
    {

        for (int i = 2; i < arr.size();)
        {
            bool first = isOdd(arr, i - 2);
            bool second = isOdd(arr, i - 1);
            if (first && second)
            {
                bool third = isOdd(arr, i);
                if (third)
                {
                    return true;
                }
                else
                {
                    i += 3;
                }
            }
            else if (first)
            {
                i += 2;
            }
            else if (second)
            {
                i += 1;
            }
            else
            {
                i += 2;
            }
        }
        return false;
    }
};

// 思路正确 甚至在时间复杂度上比官方题解更优，但还是O(n)

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i <= n - 3; ++i)
        {
            if ((arr[i] & 1) & (arr[i + 1] & 1) & (arr[i + 2] & 1))
            {
                return true;
            }
        }
        return false;
    }
};
