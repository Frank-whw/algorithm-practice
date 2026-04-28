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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode dummy(0, head);
        for (int i = 0; i < k; i++)
        {
            if(head == nullptr) break;
            st.push(head);
            head = head->next;
        }
        if(st.size() != k)  return dummy.next;
        ListNode *pre = st.top();
        dummy.next = pre;
        st.pop();
        while (st.size())
        {
            pre->next = st.top();
            pre = pre->next;
            st.pop();
        }
        pre->next = reverseKGroup(head, k);
        return dummy.next;
        
    }
};


class Solution {
public:
    ListNode* reverse(ListNode *head, ListNode *tail){
        ListNode *pre = tail, *cur = head;
        while(cur != tail){
            ListNode *nextNode = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nextNode;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        for (int i = 0; i < k; i++)
        {
            if(tail == nullptr) return head;
            tail = tail->next;
        }
        ListNode *newHead = reverse(head, tail);
        head->next = reverseKGroup(tail, k);
        return newHead;
        
        
    }
};
