/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head != nullptr){
            if(set.count(head)){
                return head;
            }else{
                set.insert(head);
                head = head->next;
            }
        }
        return NULL;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* slow = head, *fast = head->next;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr)
        {
            if(slow == fast){
                return slow;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }
};