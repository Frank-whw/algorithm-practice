// 152. 乘积最大子数组

// 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），
// 并返回该子数组所对应的乘积。

// 测试用例的答案是一个 32-位 整数。

// 请注意，一个只包含一个元素的数组的乘积是这个元素的值。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> d_max(n, INT_MIN);
        vector<int> d_min(n, INT_MAX);
        d_max[0] = nums[0], d_min[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                d_max[i] = max(d_max[i - 1] * nums[i], nums[i]);
                d_min[i] = min(d_min[i - 1] * nums[i], nums[i]);
            }else{
                d_max[i] = max(d_min[i - 1] * nums[i], nums[i]);
                d_min[i] = min(d_max[i - 1] * nums[i], nums[i]);
            }
            result = max(result, d_max[i]);
        }
        return result;
    }
};

// 优化：
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        // 1. 用变量代替数组，仅维护前一个位置的最大/最小乘积
        int prev_max = nums[0];  
        int prev_min = nums[0]; 
        int result = nums[0];  
        
        for (int i = 1; i < n; i++)
        {
            // 2. 临时保存prev_max
            int temp_max = prev_max;
            
            // 3. 不分支判断，直接计算当前最大/最小乘积
            prev_max = max({nums[i], prev_max * nums[i], prev_min * nums[i]});
            prev_min = min({nums[i], temp_max * nums[i], prev_min * nums[i]});
            
            // 4. 更新全局最大乘积
            result = max(result, prev_max);
        }
        
        return result;
    }
};