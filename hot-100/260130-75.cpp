// 75. 颜色分类

// 中等

// 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 对它们进行排序，
// 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

// 必须在不使用库内置的 sort 函数的情况下解决这个问题。


// 法一：统计 0、1、2 个数再重新填充数组
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0};
        for(int n : nums){
            cnt[n]++;
        }
        int pos = 0;
        for (int color = 0; color < 3; color++)
        {
            while (cnt[color]-- > 0)
            {
                nums[pos++] = color;
            } 
        }
    }
};

// 法二：单指针 遍历2遍
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] == 0){
                swap(nums[i], nums[ptr++]);
            }
        }
        for (int i = ptr; i < n; i++)
        {
            if(nums[i] == 1){
                swap(nums[i], nums[ptr++]);
            }
        }
    
    }
};


// 法三：双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // [0:s]->0    [e:(n-1)]->2
        int s = 0, e = n - 1;
        for (int i = 0; i <= e; i++)
        {
            while (i <= e && nums[i] == 2)
            {
                swap(nums[i], nums[e--]);
            }
            if(nums[i] == 0){
                swap(nums[i], nums[s++]);
            }
        } 
    }
};