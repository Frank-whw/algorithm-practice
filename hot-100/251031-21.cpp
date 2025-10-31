// 21. 合并两个有序链表

// 简单

// 将两个升序链表合并为一个新的 升序 链表并返回。
// 新链表是通过拼接给定的两个链表的所有节点组成的。
#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (list1 != NULL && list2 != NULL)
        {
            if(list1->val > list2->val){
                cur->next = list2;
                list2 = list2->next;
            }else{
                cur->next = list1;
                list1 = list1->next;
            }
            cur = cur->next;
        }
        cur->next = list1 == NULL ? list2 : list1;
        return head->next;
    }
};

// ListNode *head = new ListNode(-1)
// 必须初始化 确定值，否则就是野指针