// 24. 两两交换链表中的节点
// 中等

// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
// 你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        while (prev->next != nullptr && prev->next->next != nullptr)
        {
            ListNode* cur = prev->next;
            ListNode* next = prev->next->next;

            cur->next = next->next;
            next->next = cur;
            prev->next = next;

            prev = cur;
        }
        return dummy->next;
        
        
    }
};