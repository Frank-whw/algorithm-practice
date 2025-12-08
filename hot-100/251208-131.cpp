// 131. 分割回文串

// 中等

// 给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。
// 返回 s 所有可能的分割方案。

#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<string> divd;
    vector<vector<string>> result;
    bool isValid(){
        for(string s: divd){
            for(int i = 0; i < s.size() / 2; i++){
                if(s[i] != s[s.size() - i - 1]){
                    return false;
                }
            }
        }
        return true;
    }
    void backTrack(string s, int start){
        if(start == s.size()){
            if(isValid()){
                result.push_back(divd);
            }
        }
        for(int i = start; i < s.size(); i++){
            divd.push_back(s.substr(start, i + 1 - start));
            backTrack(s, i + 1);
            divd.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            divd.push_back(s.substr(0, i + 1));
            backTrack(s, i + 1);
            divd.pop_back();
        }
        return result;
    }
};

// 暴力通过
// ps: 
// substr(int a, int b)的意思是从索引a开始截取b个字符
// 所以用 substr(start, end - start + 1)获取 s[start:end]

class Solution {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

public:
    void dfs(const string& s, int i) {
        if (i == n) {
            ret.push_back(ans);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (f[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        dfs(s, 0);
        return ret;
    }
};