// 148. 排序链表

// 中等

// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 自顶向下归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode*head, ListNode* tail){
        if(head == NULL)    return head;
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }
        // 1.快慢指针找中点
        ListNode* slow = head, *fast = head;
        while (fast != tail)    
        {
            slow = slow->next;
            fast = fast->next;
            if(fast != tail){
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
        
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy, *temp1 = head1, *temp2 = head2;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val <= temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            }else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1 != nullptr){
            temp->next = temp1;
        }else if (temp2 != nullptr){
            temp->next = temp2;
        }
        return dummy->next;
    }
};

// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)