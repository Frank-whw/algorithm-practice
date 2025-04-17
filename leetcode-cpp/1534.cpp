// 1534. 统计好三元组
// 简单

// 提示
// 给你一个整数数组 arr ，以及 a、b 、c 三个整数。请你统计其中好三元组的数量。

// 如果三元组 (arr[i], arr[j], arr[k]) 满足下列全部条件，则认为它是一个 好三元组 。

// 0 <= i < j < k < arr.length
// |arr[i] - arr[j]| <= a
// |arr[j] - arr[k]| <= b
// |arr[i] - arr[k]| <= c
// 其中 |x| 表示 x 的绝对值。

// 返回 好三元组的数量 。

#include <bits/stdc++.h>
class Solution
{

public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        int count = 0;
        for (int i = 0; i < arr.size() - 2; i++)
        {
            for (int j = i + 1; j < arr.size() - 1; j++)
            {
                for (int k = j + 1; k < arr.size(); k++)
                {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                    {
                        cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
                        count += 1;
                    }
                }
            }
        }
        return count;
    }
};


// 剪纸优化
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (abs(arr[i] - arr[j]) > a) continue; // 提前剪枝
                for (int k = j + 1; k < n; ++k) {
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

// 最优解 前缀和？
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0, n = arr.size();
        vector<int> sum(1001, 0);
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (abs(arr[j] - arr[k]) <= b) {
                    int lj = arr[j] - a, rj = arr[j] + a;
                    int lk = arr[k] - c, rk = arr[k] + c;
                    int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));
                    if (l <= r) {
                        if (l == 0) {
                            ans += sum[r];
                        }
                        else {
                            ans += sum[r] - sum[l - 1];
                        }
                    }
                }
            }
            for (int k = arr[j]; k <= 1000; ++k) {
                ++sum[k];
            }
        }
        return ans;
    }
};

链接：https://leetcode.cn/problems/count-good-triplets/solutions/371340/tong-ji-hao-san-yuan-zu-by-leetcode-solution/

// 