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

// my solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if((head == nullptr) || (head->next == nullptr))
            return head;
        
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp;
        while(cur != nullptr){
            tmp = cur->next;    // 保存cur->next
            cur->next = pre;    // 改变cur->next的指向
            pre = cur;
            cur = tmp;
        }   // 退出循环时cur = nullptr, 到了尾结点->next
        return pre;
    }
};
