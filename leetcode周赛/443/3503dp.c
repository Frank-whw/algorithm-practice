// 3503. 子字符串连接后的最长回文串 I
// 给你两个字符串 s 和 t。

// 你可以从 s 中选择一个子串（可以为空）以及从 t 中选择一个子串（可以为空），然后将它们 按顺序 连接，得到一个新的字符串。

// 返回可以由上述方法构造出的 最长 回文串的长度。

// 回文串 是指正着读和反着读都相同的字符串。

// 子字符串 是指字符串中的一个连续字符序列。
#include <stdbool.h>
int foo(char *str)
{
    int n = strlen(str);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < n && str[l] == str[r])
        {
            ans = fmax(ans, r - l + 1);
            l--;
            r++;
        }
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && str[l] == str[r])
        {
            ans = fmax(ans, r - l + 1);
            l--;
            r++;
        }
    }
    return ans;
}
// 反转字符串
void reverse(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int computePal(const char *str, int start, int end, int isStart)
{
    int maxLen = 0;
    if (isStart)
    {
        for (int j = start; j < strlen(str); j++)
        {
            int ok = 1;
            int l = start, r = j;
            while (l < r)
            {
                if (str[l] != str[r])
                {
                    ok = 0;
                    break;
                }
                l++;
                r--;
            }
            if (ok)
            {
                if (j - start + 1 > maxLen)
                {
                    maxLen = j - start + 1;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i <= end; i++)
        {
            int ok = 1;
            int l = i, r = end;
            while (l < r)
            {
                if (str[l] != str[r])
                {
                    ok = 0;
                    break;
                }
                l++;
                r--;
            }
            if (ok)
            {
                if (end - i + 1 > maxLen)
                {
                    maxLen = end - i + 1;
                }
            }
        }
    }
    return maxLen;
}

int longestPalindrome(char *s, char *t)
{
    int n = strlen(s), m = strlen(t);
    int ans = fmax(foo(s), foo(t));

    int *palS = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        palS[i] = computePal(s, i, 0, 1);
    }

    int *palT = (int *)malloc(m * sizeof(int));
    for (int j = 0; j < m; j++)
    {
        palT[j] = computePal(t, 0, j, 0);
    }

    char *tr = (char *)malloc((m + 1) * sizeof(char));
    strcpy(tr, t);
    reverse(tr);

    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((m + 1) * sizeof(int));
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == tr[j])
            {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int L = dp[i][j];
            if (L > 0)
            {
                int base = 2 * L;
                if (base > ans)
                {
                    ans = base;
                }
                if (i + L < n)
                {
                    int newLen = base + palS[i + L];
                    if (newLen > ans)
                    {
                        ans = newLen;
                    }
                }
                int pos = m - (j + L);
                if (pos > 0)
                {
                    int newLen = base + palT[pos - 1];
                    if (newLen > ans)
                    {
                        ans = newLen;
                    }
                }
            }
        }
    }

    return ans;
}