// 206. 反转链表
// 简单

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

#include <bits/stdc++.h>
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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr) { // 处理空链表，避免栈空
            return nullptr;
        }
        stack<ListNode *> stack;
        ListNode *cur = head;
        while (cur != NULL)
        {
            stack.push(cur);
            cur = cur->next;
        }
        ListNode *newHead = stack.top();
        stack.pop();
        cur = newHead;
        while (!stack.empty())
        {
            cur->next = stack.top();
            stack.pop();
            cur = cur->next;
        }
        cur->next = nullptr; // 断开最后一个节点的原链接，避免环
        return newHead;
    }
};

// 傻了

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};