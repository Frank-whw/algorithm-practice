#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int n = s.size();
        if (n <= 1)
            return s;

        int letter[26] = {0};
        for (char c : s)
        {
            letter[c - 'a']++;
        }

        string left;     // 存储回文的左半部分
        char mid = '\0'; 

        // 构建左半部分并确定中间字符
        for (int j = 0; j < 26; j++)
        { // 按字典序从小到大遍历字符
            int cnt = letter[j];
            if (n % 2 == 1)
            { // 处理奇数长度
                if (cnt % 2 == 1)
                { // 发现奇数次字符
                    if (mid == '\0')
                    { // 仅保留第一个（最小的）奇数字符
                        mid = 'a' + j;
                        cnt--; // 扣除中间字符的一个
                    }
                    else
                    {                   // 其他奇数字符需成对使用
                        cnt -= cnt % 2; // 转为偶数
                    }
                }
            }
            else
            { // 处理偶数长度，所有字符必须成对
                cnt -= cnt % 2;
            }
            // 添加当前字符的一半到左半部分
            string tmp(cnt / 2, 'a' + j);
            left += tmp;
            letter[j] = 0; // 标记已处理
        }

        // 构建回文：左半部分 + 中间字符 + 左半部分反转
        string palindrome = left;
        if (mid != '\0')
        {
            palindrome += mid;
        }
        // 反转左半部分得到右半部分
        string right = left;
        reverse(right.begin(), right.end());
        palindrome += right;

        return palindrome;
    }
};