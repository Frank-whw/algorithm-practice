// 2444. 统计定界子数组的数目
// 困难

// 提示
// 给你一个整数数组 nums 和两个整数 minK 以及 maxK 。

// nums 的定界子数组是满足下述条件的一个子数组：

// 子数组中的 最小值 等于 minK 。
// 子数组中的 最大值 等于 maxK 。
// 返回定界子数组的数目。

// 子数组是数组中的一个连续部分。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long result = 0;

private:
    void countHelper(vector<int> &nums, int start, int end, int minK, int maxK)
    {
        // nums[start:end]的元素都是符合条件的，不包括nums[end]
        // 用滑动窗口做？
        int l = start, r = start;
        unordered_map<int, int> map; // 记录i出现的次数
        while (r < end)
        {
            map[nums[r]] += 1;
            while (map[minK] && map[maxK] && l <= r)
            {
                cout << "l:" << l << " " << r << endl;

                result += end - r; // 剩下的肯定都符合
                int key = nums[l++];
                map[key] -= 1;
                if (map[key] == 0)
                {
                    map.erase(key);
                }
            }
            r += 1;
        }
    }

public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        using ll = long long;
        int l = 0, n = nums.size(), r = 0;
        while (r < n)
        {
            if (nums[r] > maxK || nums[r] < minK)
            {
                countHelper(nums, l, r, minK, maxK);
                l = r + 1;
                r = l;
            }
            else
            {
                r++;
            }
        }
        countHelper(nums, l, r, minK, maxK);
        return result;
    }
};

// 我的思路：
// 先遍历一遍数组，把原数组分割成若干段，对每段数组调用helper函数处理
// 在helper函数中用滑动窗口方法，枚举右边界，滑动左边界，用全局变量result记录符合条件的数组
// 时间复杂度: O(n)
// 空间复杂度：O(n)

// 官方题解:
// 对于每个段，我们记 border 为段左边界（为了方便计算，令第 border+1 个数才是段内的第一个数字），
// 然后从左到右遍历时，记当前位置 i 左侧第一个数值等于 minK 的位置是 last_min，
// 左侧第一个数值等于 maxK 的位置是 last_max，
// 那么在这个段内，以 i 为右端点的定界子数组共有 min(last_min,last_max)−border 个。
// 时间复杂度: O(n)
// 空间复杂度：O(1)

class Solution
{
public:
    using ll = long long;
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        ll res = 0;
        int border = -1, last_min = -1, last_max = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                last_max = -1;
                last_min = -1;
                border = i;
            }
            if (nums[i] == minK)
            {
                last_min = i;
            }
            if (nums[i] == maxK)
            {
                last_max = i;
            }
            if (last_min != -1 && last_max != -1)
            {
                res += min(last_min, last_max) - border;
            }
        }
        return res;
    }
};
