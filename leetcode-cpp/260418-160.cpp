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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        while(headA != nullptr){
            set.insert(headA);
            headA = headA->next;
        }
        while (headB != nullptr)
        {
            if(set.find(headB) != set.end()){
                return headB;
            }else{
                headB = headB->next;
            }
        }
        return nullptr;
        
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 法二 用2个指针 pa pb分别从heada headb开始走，走完当前的链表 走对方的链表，
        // 如果2个链表有公共节点 会在第2次相遇（如果2个链表长度一致 第1次就会相遇）
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* pa = headA, *pb = headB;
        while (pa != pb)
        {
            pa = pa == nullptr ? headB : pa->next;
            pb = pb == nullptr ? headA : pb->next;
        }
        return pa;
    }
};
