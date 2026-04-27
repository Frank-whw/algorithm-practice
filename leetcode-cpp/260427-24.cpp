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

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *first = head, *second = head->next, *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        while (first && second)
        {
            ListNode *nextNode = second->next;
            first->next = nextNode;
            second->next = first;
            pre->next = second;
            pre = first;
            first = nextNode;
            
            if(first) {
                cout << first->val;
                second = first->next;
            }
        
        }    
        return dummy->next;
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *pre = &dummy;
        while (pre->next && pre->next->next)
        {
            ListNode *first = pre->next;
            ListNode *second = pre->next->next;
            first->next = second->next;
            pre->next = second;
            second->next = first;
            pre = first;
        }
        return dummy.next;
        
    }
};