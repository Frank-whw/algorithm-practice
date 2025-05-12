// 2094. 找出 3 位偶数
// 简单

// 提示
// 给你一个整数数组 digits ，其中每个元素是一个数字（0 - 9）。数组中可能存在重复元素。

// 你需要找出 所有 满足下述条件且 互不相同 的整数：

// 该整数由 digits 中的三个元素按 任意 顺序 依次连接 组成。
// 该整数不含 前导零
// 该整数是一个 偶数
// 例如，给定的 digits 是 [1, 2, 3] ，整数 132 和 312 满足上面列出的全部条件。

// 将找出的所有互不相同的整数按 递增顺序 排列，并以数组形式返回。

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        unordered_set<int> nums;
        for (int i = 0; i < digits.size(); i++)
        {
            for (int j = 0; j < digits.size(); j++)
            {
                if (i != j)
                {
                    for (int k = 0; k < digits.size(); k++)
                    {
                        if (k != i && k != j)
                        {
                            int sum = 100 * digits[i] + 10 * digits[j] + digits[k];
                            if (sum > 99 && sum % 2 == 0)
                            {
                                nums.insert(sum);
                            }
                        }
                    }
                }
            }
        }
        // 转化为升序排序的数组
        vector<int> res;
        for (const int num : nums)
        {
            res.push_back(num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

// 为了避免重复，先用哈希表存储，再传入vector中，用sort排序