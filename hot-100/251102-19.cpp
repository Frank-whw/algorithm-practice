// 19. 删除链表的倒数第 N 个结点

// 中等
// 相关标签

// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

#include <bits/stdc++.h>
using namespace std;

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *cur = head;
        int size = 0;
        vector<ListNode *> nodes;
        while (cur)
        {
            nodes.push_back(cur);
            cur = cur->next;
            size++;
        }
        int index = size - n;
        if (size == 1)
            return nullptr;
        if (index == 0)
            return nodes[1];
        else
        {
            nodes[index - 1]->next = nodes[index]->next;
            return head;
        }
    }
};

// 法1：直接用数组存node的地址
// 法2：栈
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        stack<ListNode *> stk;
        ListNode *cur = dummy;
        while (cur)
        {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; ++i)
        {
            stk.pop();
        }
        ListNode *prev = stk.top();
        prev->next = prev->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};