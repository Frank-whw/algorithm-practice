// 139. 单词拆分
// 中等

// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
// 如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
#include<stdbool.h>
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int sSize = strlen(s);
    // dp[i]: 前i个字符能否组成单词
    bool* dp = malloc(sizeof(bool ) * (sSize+ 1));
    for(int i = 0; i <= sSize; i++){
        dp[i] = false;
    }
    dp[0] = true;

    //遍历
    for(int j = 0; j <= sSize; j++){
        if (!dp[j]) continue; // 如果前j个字符不能组成单词，跳过
        for(int word = 0; word < wordDictSize; word++){
            int wordSize = strlen(wordDict[word]);
            if(j + wordSize > sSize)   continue;
            bool match = true;
            // 检查单词是否匹配
            for (int letter = 0; letter < wordSize; letter++) {
                if (wordDict[word][letter] != s[j + letter]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                dp[j + wordSize] = true;
            }
        }
    }

    for(int i = 0 ; i<= sSize; i ++){
        printf("%d ", dp[i]);
    }
    return dp[sSize];
}

// 求组和数 外层遍历物品，内层遍历背包
// 求排列数 外层遍历背包，内存遍历物品

// 本题是求排列数
// dp[i] : 字符串长度为i的话，dp[i]为true，表示可以拆分为一个或多个在字典中出现的单词。
