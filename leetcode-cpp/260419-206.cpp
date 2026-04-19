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

// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

// 迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curNode = head, *pre = nullptr;
        while(curNode != nullptr){
            cout << curNode->val << endl;
            ListNode* nextNode = curNode->next;
            curNode->next = pre;
            pre = curNode;
            curNode = nextNode;
        }
        return pre;
    }
};