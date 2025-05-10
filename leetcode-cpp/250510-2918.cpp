// 2918. 数组的最小相等和
// 中等

// 提示
// 给你两个由正整数和 0 组成的数组 nums1 和 nums2 。

// 你必须将两个数组中的 所有 0 替换为 严格 正整数，并且满足两个数组中所有元素的和 相等 。

// 返回 最小 相等和 ，如果无法使两数组相等，则返回 -1 。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        using ll = long long;
        ll result = 0;
        int sum1 = 0, sum2 = 0, zero1 = 0, zero2 = 0;
        for (int num : nums1)
        {
            sum1 += num;
            if (num == 0)
            {
                zero1 += 1;
            }
        }
        for (int num : nums2)
        {
            sum2 += num;
            if (num == 0)
            {
                zero2 += 1;
            }
        }
        if (zero1 && zero2)
        {
            return max(zero1 + sum1, zero2 + sum2);
        }
        else if (zero1)
        {
            if (sum2 >= sum1 + zero1)
            {
                return sum2;
            }
            else
            {
                return -1;
            }
        }
        else if (zero2)
        {
            if (sum1 >= sum2 + zero2)
            {
                return sum1;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if (sum1 == sum2)
            {
                return sum1;
            }
            else
            {
                return -1;
            }
        }
    }
};

// 用分类讨论思路，思路正确 可以通过632/636个测试用例
// 后面没有通过的原因在于：分支过于复杂
// 需要整理一下
class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;
        for (int i : nums1)
        {
            sum1 += i;
            if (i == 0)
            {
                sum1++;
                zero1++;
            }
        }
        for (int i : nums2)
        {
            sum2 += i;
            if (i == 0)
            {
                sum2++;
                zero2++;
            }
        }
        if (!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2)
        {
            return -1;
        }
        return max(sum1, sum2);
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/solutions/3665133/shu-zu-de-zui-xiao-xiang-deng-he-by-leet-5cam/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
