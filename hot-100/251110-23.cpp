// 23. 合并 K 个升序链表

// 困难

// 给你一个链表数组，每个链表都已经按升序排列。

// 请你将所有链表合并到一个升序链表中，返回合并后的链表。

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        return mergeKLists(lists, 0, n);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists, int start, int end)
    {
        if(start >= end)    return nullptr;
        if (start == end - 1)
            return lists[start];
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKLists(lists, start ,mid);
        ListNode* right = mergeKLists(lists, mid, end); 
        return merge(left, right);
    }
    ListNode *merge(ListNode* list1, ListNode* list2){
        ListNode *dummy = new ListNode(0);
            ListNode *head = dummy, *temp1 = list1, *temp2 = list2;
            while (temp1 != nullptr && temp2 != nullptr)
            {
                if (temp1->val <= temp2->val)
                {
                    head->next = temp1;
                    temp1 = temp1->next;
                }
                else
                {
                    head->next = temp2;
                    temp2 = temp2->next;
                }
                head = head->next;
            }
            if (temp1 != nullptr)
                head->next = temp1;
            else if (temp2 != nullptr)
                head->next = temp2;
            return dummy->next;
    }
};

// 第一想法就是分支，重载函数mergeKLists