// 参考 https://programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF

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
        if((head == NULL) || (head->next == NULL))
            return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while((fast!=NULL) && (fast->next!=NULL)) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                ListNode *node1 = head;
                ListNode *node2 = fast;
                while(node1 != node2) {
                    node1 = node1->next;
                    node2 = node2->next;
                }
                return node1;
            }
        }
        return NULL;
    }
};
