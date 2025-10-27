// 234. 回文链表

// 简单

// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
// 如果是，返回 true ；否则，返回 false 。
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string s = "";
        ListNode* cur = head;
        while(cur){
            s += cur->val;
            cur = cur->next;
        }
        string new_s = s;
        reverse(new_s.begin(), new_s.end());
        if(s == new_s){
            return true;
        }
        else{
            return false;
        }
    }
};

// 用reverse代替回文判断