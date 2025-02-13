// 474. 一和零
// 中等

// 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
// 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

int zeroCount(char *s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '0')
        {
            count += 1;
        }
    }
    return count;
}
int oneCount(char *s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '1')
        {
            count += 1;
        }
    }
    return count;
}

int findMaxForm(char **strs, int strsSize, int m, int n)
{
    // 定义dp[i][j]：最多有i个0，j个1的子集最大长度
    int **dp = malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++)
    {
        dp[i] = malloc(sizeof(int) * (n + 1));
    }

    // 初始化
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }

    
    // 遍历
    for (int index = 0; index < strsSize; index++)
    {
        int one = oneCount(strs[index]);
        int zero = zeroCount(strs[index]);

        for (int i = m; i >= zero; i--)
        {
            for (int j = n; j >= one; j--)
            {
                dp[i][j] = fmax(dp[i][j], dp[i - zero][j - one] + 1);
            }
        }
        // printf("index = %d\n",index);
        // for (int i = 0; i <= m; i++)
        // {
        //     for (int j = 0; j <= n; j++)
        //     {
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        
    }


    
    return dp[m][n];
}

// dp 01背包的应用
// 此类 选 与 不选 的题型优先考虑背包问题，本题是每个物品的数量只有一个且只能选一次，属于是01背包问题
// 确定dp[i][j]的意义——多刷题之后越来越有感觉
// 递推公式：dp[i][j] = fmax(dp[i][j], dp[i - zero][j - one] + 1);
// 初始化——背包问题 全初始为0 （遇到的几道题都是这样）
// 遍历顺序！！！被这边坑了30min
// 这边是从后往前遍历
// 如果正向遍历，dp[i - zero][j - one] 可能已经在当前物品的选择过程中被更新过，这样就相当于当前物品被重复选择了。
// 而逆向遍历可以保证在更新 dp[i][j] 时，
// dp[i - zero][j - one] 还是上一个物品选择时的值，即保证每个物品只被选择一次。