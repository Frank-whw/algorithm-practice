// 79. 单词搜索

// 中等

// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
// 如果 word 存在于网格中，返回 true ；否则，返回 false 。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，
// 其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool result = false;
    int direction[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    void existLetter(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, string word, int index)
    {
        if (index == word.size())
        {
            result = true;
        }
        if (result)
            return;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + direction[i][0], ny = y + direction[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visited[nx][ny] && board[nx][ny] == word[index])
            {
                visited[nx][ny] = true;
                existLetter(board, visited, nx, ny, word, index + 1);
                visited[nx][ny] = false;
            }
        }
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        char ch = word[0];
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (ch == board[i][j] && !visited[i][j])
                {
                    visited[i][j] = true;
                    existLetter(board, visited, i, j, word, 1);
                    visited[i][j] = false;
                }
            }
        }
        return result;
    }
};

// 优化1：
// 原代码在 index == word.size() 时才设置 result = true，但递归仍会继续执行（直到所有方向遍历完）。
// 可以在找到结果后 立即终止所有递归（通过 return true 传递终止信号），避免无效递归。
class Solution
{
private:
    int direction[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    bool existLetter(vector<vector<char>> &board, vector<vector<bool>> &visited, int x, int y, string word, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + direction[i][0], ny = y + direction[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visited[nx][ny] && board[nx][ny] == word[index])
            {
                visited[nx][ny] = true;
                if (existLetter(board, visited, nx, ny, word, index + 1))
                {
                    return true;
                }
                visited[nx][ny] = false;
            }
        }
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        char ch = word[0];
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (ch == board[i][j] && !visited[i][j])
                {
                    visited[i][j] = true;
                    if (existLetter(board, visited, i, j, word, 1))
                    {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
// 提升了4ms
// 优化2：
// 复用原数组标记访问（避免额外 visited 数组）
class Solution
{
private:
    int direction[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    bool existLetter(vector<vector<char>> &board, int x, int y, string word, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + direction[i][0], ny = y + direction[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == word[index])
            {
                board[nx][ny] = '#';
                if (existLetter(board, nx, ny, word, index + 1))
                {
                    return true;
                }
                board[nx][ny] = word[index];
            }
        }
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        char ch = word[0];
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (ch == board[i][j])
                {
                    board[i][j] = '#';
                    if (existLetter(board, i, j, word, 1))
                    {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
};
// 提升了40ms

// 优化3： 
// 前置检查：如果单词长度 > 网格总字符数（word.size() > m*n），直接返回 false（不可能存在）。
// 统计字符频率：如果网格中目标单词的某个字符出现次数 < 单词中该字符的出现次数，直接返回 false（提前排除不可能情况）。
class Solution
{
private:
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool backtrack(vector<vector<char>> &board, const string &word, int x, int y, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() &&
                board[nx][ny] == word[index])
            {
                board[nx][ny] = '#';
                if (backtrack(board, word, nx, ny, index + 1))
                {
                    return true;
                }
                board[nx][ny] = word[index];
            }
        }
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        int len = word.size();

        // 前置剪枝 1：单词长度超过网格总字符数，直接返回 false
        if (len > m * n)
        {
            return false;
        }

        // 前置剪枝 2：统计字符频率，排除不可能情况
        unordered_map<char, int> board_cnt, word_cnt;
        for (const auto &row : board)
        {
            for (char c : row)
            {
                board_cnt[c]++;
            }
        }
        for (char c : word)
        {
            word_cnt[c]++;
            // 网格中该字符数量不足，直接返回 false
            if (board_cnt[c] < word_cnt[c])
            {
                return false;
            }
        }

        // 遍历网格，找到单词起点（第一个字符匹配）
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0])
                {
                    // 标记起点为已访问
                    board[i][j] = '#';
                    // 递归查找，找到则返回 true
                    if (backtrack(board, word, i, j, 1))
                    {
                        return true;
                    }
                    // 回溯：恢复起点字符
                    board[i][j] = word[0];
                }
            }
        }

        // 所有起点都没找到
        return false;
    }
};