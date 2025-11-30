// 208. 实现 Trie (前缀树)

// 中等

// Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，
// 用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。

// 请你实现 Trie 类：

// Trie() 初始化前缀树对象。
// void insert(String word) 向前缀树中插入字符串 word 。
// boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
// boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。

#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
    vector<Trie*> children; 
    bool isEnd; // flag whether current node is the end of the word
    Trie* searchPrefix(string prefix){
        Trie* node = this; 
        for(char ch : prefix){
            ch -= 'a';
            if(node->children[ch] == nullptr){
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }
public:
    Trie(): children(26), isEnd(false){} // initialize the array
    
    void insert(string word) {
        Trie* node = this;
        for(char ch : word){
            ch -= 'a';
            if(node->children[ch] == nullptr){
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd; // node exists + the end of the word = word exists
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */