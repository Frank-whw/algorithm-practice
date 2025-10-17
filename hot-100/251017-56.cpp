// 56. 合并区间

// 中等

// 相关企业
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
// 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > end)
            {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                end = max(intervals[i][1], end);
            }
            
        }
        // 加入最后一个合并的区间
        ans.push_back({start, end});
        return ans;
    }
};