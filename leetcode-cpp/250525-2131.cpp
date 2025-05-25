// 2131. 连接两字母单词得到的最长回文串
// 中等

// 提示
// 给你一个字符串数组 words 。words 中每个元素都是一个包含 两个 小写英文字母的单词。

// 请你从 words 中选择一些元素并按 任意顺序 连接它们，并得到一个 尽可能长的回文串 。每个元素 至多 只能使用一次。

// 请你返回你能得到的最长回文串的 长度 。如果没办法得到任何一个回文串，请你返回 0 。

// 回文串 指的是从前往后和从后往前读一样的字符串。

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> freq;
        for (const string &word : words)
        {
            ++freq[word];
        }
        int res = 0;
        bool mid = false;
        for (const auto &[word, cnt] : freq)
        {
            string rev = string(1, word[1]) + word[0];
            if (word == rev)
            {
                if (cnt % 2 == 1)
                {
                    mid = true;
                }
                res += 2 * (cnt / 2 * 2);
            }
            else if (word > rev)
            {
                res += 4 * min(freq[word], freq[rev]);
            }
        }
        if (mid)
        {
            res += 2;
        }
        return res;
    }
};

// 我们用哈希表统计 words 中每个单词的出现次数。随后，我们遍历哈希表的所有元素，
// 并用 res 维护可能构成回文字符串的最长长度，
// 同时用初值为 false 的布尔变量 mid 判断是否存在可以作为中心单词的、出现奇数次的回文单词。
// 在遍历到字符串 word 时，我们首先求出它反转后的字符串 rev，此时根据 word 与 rev 的关系，
// 有以下两种情况：

// word!=rev
// 此时我们需要统计两者在 words 出现次数的最小值，即为成对选择的最多数目。
// 假设此时对数为 n，则其对最长回文字符串贡献的字符长度为 4n，我们将 res 加上对应值；

// word==rev
// 此时可以构成的对数为 ⌊m/2⌋，即对最长回文字符串贡献的字符长度为 4⌊m/2⌋，
// 我们同样将 res 加上对应值。除此以外，我们还需要判断 word 的出现次数 m 是否为奇数：

//     如果 m 为奇数，则存在可以作为中心单词的剩余回文单词，我们将 mid 置为 true；
//     如果 m 为偶数，则不存在可以作为中心单词的剩余回文单词，我们不改变 mid 的取值。

// 最后，我们根据 mid 的取值，判断最长回文串是否含有中心单词。如果 mid 为 true，则代表含有，
// 我们将 res 加上 2；反之则没有，我们不进行任何操作。

