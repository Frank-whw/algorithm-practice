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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head != nullptr){
            if(set.count(head)){
                return true;
            }else{
                set.insert(head);
                head = head->next;
            }
        }
        return false;
        
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode* slow = head, *fast = head->next;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr)
        {
            if(slow == fast){
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
        
    }
};