// 本题的重点在于: 将两个链表的尾部对齐, 从而找到交汇点
// https://leetcode.cn/problems/intersection-of-two-linked-lists/solutions/10774/tu-jie-xiang-jiao-lian-biao-by-user7208t

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
        if((headA == NULL) || (headB == NULL)) {
            return NULL;
        }
        ListNode *pA = headA, *pB = headB;
        while(pA != pB) {
            pA = (pA == NULL ? headB : pA->next);
            pB = (pB == NULL ? headA : pB->next);
        }
        return pA;
    }
};
