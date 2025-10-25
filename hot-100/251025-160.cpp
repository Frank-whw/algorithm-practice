// 160. 相交链表
// 简单

// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
// 如果两个链表不存在相交节点，返回 null 。

#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> set;
        ListNode *curA = headA;
        while (curA != NULL)
        {
            set.insert(curA);
            curA = curA->next;
        }
        ListNode *curB = headB;
        while (curB != NULL)
        {
            if (set.find(curB) != set.end())
            {
                return curB;
            }
            curB = curB->next;
        }
        return NULL;
    }
};