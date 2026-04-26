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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        while (head)
        {
            nodes.push_back(head);
            head = head->next;
        }
        int size = nodes.size();
        if(size == 1)   return nullptr;
        if(n == 1){
            nodes[size - 2]->next = nullptr;
            return nodes[0];
        }
        int index = nodes.size() - n;
        if(index == 0){
            return nodes[1];
        }
        else{
            nodes[index - 1]->next = nodes[index + 1];
            return nodes[0];
        }
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy, *fast = dummy;
        while (n--)
        {
            fast = fast->next;
        }
        while (fast->next)  
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
        
    }
};