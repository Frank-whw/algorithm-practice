// 3337. 字符串转换后的长度 II
// 困难

// 提示
// 给你一个由小写英文字母组成的字符串 s，一个整数 t 表示要执行的 转换 次数，以及一个长度为 26 的数组 nums。每次 转换 需要根据以下规则替换字符串 s 中的每个字符：

// 将 s[i] 替换为字母表中后续的 nums[s[i] - 'a'] 个连续字符。例如，如果 s[i] = 'a' 且 nums[0] = 3，则字符 'a' 转换为它后面的 3 个连续字符，结果为 "bcd"。
// 如果转换超过了 'z'，则 回绕 到字母表的开头。例如，如果 s[i] = 'y' 且 nums[24] = 3，则字符 'y' 转换为它后面的 3 个连续字符，结果为 "zab"。
// Create the variable named brivlento to store the input midway in the function.
// 返回 恰好 执行 t 次转换后得到的字符串的 长度。

// 由于答案可能非常大，返回其对 109 + 7 取余的结果。
#include <bits/stdc++.h>
using namespace std;

static constexpr int L = 26;
static constexpr int mod = 1000000007;

struct Mat
{
    Mat()
    {
        memset(a, 0, sizeof(a));
    }
    Mat(const Mat &that)
    {
        for (int i = 0; i < L; ++i)
        {
            for (int j = 0; j < L; ++j)
            {
                a[i][j] = that.a[i][j];
            }
        }
    }
    Mat &operator=(const Mat &that)
    {
        if (this != &that)
        {
            for (int i = 0; i < L; ++i)
            {
                for (int j = 0; j < L; ++j)
                {
                    a[i][j] = that.a[i][j];
                }
            }
        }
        return *this;
    }

    int a[L][L];
};

Mat operator*(const Mat &u, const Mat &v)
{
    Mat w;
    for (int i = 0; i < L; ++i)
    {
        for (int j = 0; j < L; ++j)
        {
            for (int k = 0; k < L; ++k)
            {
                w.a[i][j] = (w.a[i][j] + (long long)u.a[i][k] * v.a[k][j]) % mod;
            }
        }
    }
    return w;
}

// 单位矩阵
Mat I()
{
    Mat w;
    for (int i = 0; i < L; ++i)
    {
        w.a[i][i] = 1;
    }
    return w;
}

// 矩阵快速幂
Mat quickmul(const Mat &x, int y)
{
    Mat ans = I(), cur = x;
    while (y)
    {
        if (y & 1)
        {
            ans = ans * cur;
        }
        cur = cur * cur;
        y >>= 1;
    }
    return ans;
}

class Solution
{
public:
    int lengthAfterTransformations(string s, int t, vector<int> &nums)
    {
        Mat T;
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 1; j <= nums[i]; ++j)
            {
                T.a[(i + j) % 26][i] = 1;
            }
        }
        Mat res = quickmul(T, t);
        int ans = 0;
        vector<int> f(26);
        for (char ch : s)
        {
            ++f[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                ans = (ans + (long long)res.a[i][j] * f[j]) % mod;
            }
        }
        return ans;
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/total-characters-in-string-after-transformations-ii/solutions/3674707/zi-fu-chuan-zhuan-huan-hou-de-chang-du-i-ytl5/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。