// 25. K 个一组翻转链表

// 困难

// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy->next;
        int size = 0;
        while (cur)
        {
            size++;
            cur = cur->next;
        }
        if (size < k)
            return dummy->next;
        vector<ListNode *> nodes;
        cur = dummy->next;
        for (int i = 0; i < k; i++)
        {
            nodes.push_back(cur);
            cur = cur->next;
        }
        for (int i = k - 1; i > 0; i--)
        {

            nodes[i]->next = nodes[i - 1];
        }
        nodes[0]->next = reverseKGroup(cur, k);
        return nodes[k - 1];
    }
};

// 递归直接拿下