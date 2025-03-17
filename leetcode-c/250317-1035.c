// 1035. 不相交的线
// 中等

// 在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
// 现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足：
// 1.nums1[i] == nums2[j]
// 2.绘制的直线不与任何其他连线（非水平线）相交。

// 请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
// 以这种方法绘制线条，并返回可以绘制的最大连线数。

int maxUncrossedLines(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    // dp[i][j]: nums1前i个元素和nums2前j个元素，且nums1[i-1] == nums2[j-1]结尾的最大连线数
    int **dp = malloc(sizeof(int *) * (1 + nums1Size));
    for (int i = 0; i <= nums1Size; i++)
    {
        dp[i] = malloc(sizeof(int) * (1 + nums2Size));
    }
    // 初始化
    for (int i = 0; i <= nums1Size; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= nums2Size; j++)
    {
        dp[0][j] = 0;
    }
    // 遍历
    for (int i = 1; i <= nums1Size; i++)
    {
        for (int j = 1; j <= nums2Size; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[nums1Size][nums2Size];
}

// 一遍过