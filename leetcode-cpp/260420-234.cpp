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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p = slow, *q = nullptr;
        while (p != nullptr)
        {
            ListNode *r = p->next;
            p->next = q;
            q = p;
            p = r;
        }
        while(q != nullptr){
            if(q->val != head->val) return false;
            q = q->next;
            head = head->next;
        }
        return true;
        
    }
};