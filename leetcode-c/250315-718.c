// 718. 最长重复子数组
// 中等

// 给两个整数数组 nums1 和 nums2 ，
// 返回 两个数组中 公共的 、长度最长的子数组的长度 。

int findLength(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int result = 0;
    // dp[i][j]:由nums1前i个元素，nums2前j个元素组成的子数组，且子数组最后一个元素是num1[i] == nums2[j]
    int **dp = malloc(sizeof(int *) * nums1Size);
    for (int i = 0; i < nums1Size; i++)
    {
        dp[i] = malloc(sizeof(int) * nums2Size);
        for (int j = 0; j < nums2Size; j++)
        {
            dp[i][j] = nums1[i] == nums2[j] ? 1 : 0;
            if (dp[i][j] > result)
                result = dp[i][j];
        }
    }
    for (int i = 1; i < nums1Size; i++)
    {
        for (int j = 1; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if (dp[i][j] > result)
                result = dp[i][j];
        }
    }

    return result;
}

// 定义一个方便的dp
// 找到有意义的状态转移关系