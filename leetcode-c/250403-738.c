// 738. 单调递增的数字
// 中等

// 提示
// 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，
// 我们称这个整数是单调递增的。

// 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

int monotoneIncreasingDigits(int n)
{
    char str[11];
    // 将数字转换为字符串
    sprintf(str, "%d", n);
    int len = strlen(str);
    int flag = strlen(str);
    for (int i = len - 1; i > 0; i--)
    {
        if (str[i] < str[i - 1])
        {
            str[i - 1]--;
            flag = i;
        }
    }
    for (int i = flag; i < len; i++)
    {
        str[i] = '9';
    }
    return atoi(str);
}


// 贪心
// 第一想法是暴力
// 第二想法是找到改变单调趋势的那个数字，把后面的数字变为9，但是不会实现


