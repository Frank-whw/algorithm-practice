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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        int carry = 0;
        while (l1 && l2)
        {
            int val = l1->val + l2->val + carry;
            if (val >= 10)
            {
                carry = 1;
                val = val % 10;
            }else{
                carry = 0;
            }
            cur->next = new ListNode(val);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            int val = l1->val + carry;
            if (val >= 10)
            {
                carry = 1;
                val = val % 10;
            }else{
                carry = 0;
            }
            cur->next = new ListNode(val);
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            int val = l2->val + carry;
            if (val >= 10)
            {
                carry = 1;
                val = val % 10;
            }else{
                carry = 0;
            }
            cur->next = new ListNode(val);
            cur = cur->next;
            l1 = l2->next;
        }
        if (carry)
        {
            cur->next = new ListNode(1);
        }
        return head->next;
    }
};


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int val = v1 + v2 + carry;
            carry = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        return head->next;
    }
};