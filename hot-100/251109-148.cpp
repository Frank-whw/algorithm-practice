// 148. 排序链表

// 中等

// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

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

// 自顶向下归并排序
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        return sortList(head, nullptr);
    }
    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (head == tail)
        {
            return head;
        }
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
            }
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *cur1 = head1, *cur2 = head2;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while (cur1 != nullptr && cur2 != nullptr)
        {
            if (cur1->val <= cur2->val)
            {
                temp->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                temp->next = cur2;
                cur2 = cur2->next;
            }
            temp = temp->next;
        }
        if (cur1 != nullptr)
        {
            temp->next = cur1;
        }
        else if (cur2 != nullptr)
        {
            temp->next = cur2;
        }
        return dummy->next;
    }
};
