// 2799. 统计完全子数组的数目
// 中等

// 提示
// 给你一个由 正 整数组成的数组 nums 。

// 如果数组中的某个子数组满足下述条件，则称之为 完全子数组 ：

// 子数组中 不同 元素的数目等于整个数组不同元素的数目。
// 返回数组中 完全子数组 的数目。

// 子数组 是数组中的一个连续非空序列。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDifferentNum(vector<int> &nums)
    {
        unordered_set<int> table;
        for (int num : nums)
        {
            table.insert(num);
        }
        return table.size();
    }
    int countCompleteSubarrays(vector<int> &nums)
    {
        int result = 0;
        int types = countDifferentNum(nums);
        unordered_map<int, int> map;
        int l = 0, r = 0; // 左右边界
        while (r < nums.size())
        {
            map[nums[r]] += 1;
            while (map.size() == types)
            {
                result += nums.size() - r;
                int key = nums[l++];
                if (--map[key] == 0)
                {
                    map.erase(key);
                }
            }
            r++;
        }

        return result;
    }
};


// 笑死，有个很重要的点：子数组的元素种类 不可能比 整个数组不同元素的数目 还多
// 所以当满足map.size() == types的时候，剩下的nums.size() - r都符合条件要求