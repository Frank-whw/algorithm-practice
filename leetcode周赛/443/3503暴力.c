// 3503. 子字符串连接后的最长回文串 I
// 给你两个字符串 s 和 t。

// 你可以从 s 中选择一个子串（可以为空）以及从 t 中选择一个子串（可以为空），然后将它们 按顺序 连接，得到一个新的字符串。

// 返回可以由上述方法构造出的 最长 回文串的长度。

// 回文串 是指正着读和反着读都相同的字符串。

// 子字符串 是指字符串中的一个连续字符序列。
#include <stdbool.h>
bool isHuiWeng(char *string, int start, int end)
{
    int l = start, r = end - 1;
    while (l < r)
    {
        if (string[l] != string[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int longestPalindrome(char *s, char *t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    int max_length = 0;
    for (int i = 0; i < len_s; i++)
    {
        for (int j = i; j < len_s; j++)
        {
            for (int k = 0; k < len_t; k++)
            {
                for (int l = k; l < len_t; l++)
                {
                    int combined_len = (j - i) + (l - k);
                    char combined[combined_len + 1];
                    int index = 0;
                    // 拼接 s 的子串
                    for (int m = i; m < j; m++)
                    {
                        combined[index++] = s[m];
                    }
                    // 拼接 t 的子串
                    for (int n = k; n < l; n++)
                    {
                        combined[index++] = t[n];
                    }
                    combined[index] = '\0';
                    // 检查拼接结果是否为回文串
                    if (isHuiWeng(combined, 0, combined_len - 1))
                    {
                        if (combined_len > max_length)
                        {
                            max_length = combined_len;
                        }
                    }
                }
            }
        }
    }
    return max_length;
}
