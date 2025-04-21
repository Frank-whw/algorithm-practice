// 2145. 统计隐藏数组数目
// 中等

// 提示
// 给你一个下标从 0 开始且长度为 n 的整数数组 differences ，
// 它表示一个长度为 n + 1 的 隐藏 数组 相邻 元素之间的 差值 。
// 更正式的表述为：我们将隐藏数组记作 hidden ，那么 differences[i] = hidden[i + 1] - hidden[i] 。

// 同时给你两个整数 lower 和 upper ，它们表示隐藏数组中所有数字的值都在 闭 区间 [lower, upper] 之间。

// 比方说，differences = [1, -3, 4] ，lower = 1 ，upper = 6 ，
// 那么隐藏数组是一个长度为 4 且所有值都在 1 和 6 （包含两者）之间的数组。
// [3, 4, 1, 5] 和 [4, 5, 2, 6] 都是符合要求的隐藏数组。
// [5, 6, 3, 7] 不符合要求，因为它包含大于 6 的元素。
// [1, 2, 3, 4] 不符合要求，因为相邻元素的差值不符合给定数据。
// 请你返回 符合 要求的隐藏数组的数目。如果没有符合要求的隐藏数组，请返回 0 。

#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// private:
//     int minIndexOfArrays(vector<long long> &arr)
//     {
//         int minIndex = 0;
//         for (int i = 1; i < arr.size(); i++)
//         {
//             if (arr[i] < arr[minIndex])
//             {
//                 minIndex = i;
//             }
//         }
//         return minIndex;
//     }
//     int maxIndexOfArrays(vector<long long> &arr)
//     {
//         int maxIndex = 0;
//         for (int i = 1; i < arr.size(); i++)
//         {
//             if (arr[i] > arr[maxIndex])
//             {
//                 maxIndex = i;
//             }
//         }
//         return maxIndex;
//     }

// public:
//     int numberOfArrays(vector<int> &differences, int lower, int upper)
//     {
//         using ll = long long;
//         vector<ll> arr(differences.size() + 1, 0);
//         arr[0] = 0;
//         for (int i = 1; i <= differences.size(); i++)
//         {
//             arr[i] = differences[i - 1] + arr[i - 1];
//         }
//         int minIndex = minIndexOfArrays(arr) + 1, maxIndex = maxIndexOfArrays(arr) + 1;
//         cout << minIndex << " " << maxIndex << endl;
//         ll vary = 0;
//         for (int i = min(minIndex, maxIndex); i < max(minIndex, maxIndex); i++)
//         {
//             vary += differences[i - 1];
//         }
//         cout << vary << " vary" << endl;
//         return upper - lower + 1 > abs(vary) ? upper - lower - abs(vary) + 1 : 0;
//     }
// };

// 以上思路是对的，而且也能accept，问题在于代码很冗长 逻辑冗余

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        int x = 0, y = 0, cur = 0;
        for (int d : differences)
        {
            cur += d;
            x = min(x, cur);
            y = max(y, cur);
            if (y - x > upper - lower)
            {
                return 0;
            }
        }
        return (upper - lower) - (y - x) + 1;
    }
};
