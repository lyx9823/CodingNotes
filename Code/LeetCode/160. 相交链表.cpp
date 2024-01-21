// 本题的重点在于: 将两个链表的尾部对齐, 从而找到交汇点
// https://leetcode.cn/problems/intersection-of-two-linked-lists/solutions/10774/tu-jie-xiang-jiao-lian-biao-by-user7208t

// 解释1: 若相交, 链表A: a+c, 链表B, b+c; a+c+b+c = b+c+a+c, 则会在公共处c起点相遇; 若不相交, a+b = b+a, 因此相遇处是NULL

// 解释2: pA走过的路径为A链+B链, pB走过的路径为B链+A链, pA和pB走过的长度都相同, 都是A链和B链的长度之和, 相当于将两条链从尾端对齐; 
// 如果相交，则会提前在相交点相遇，如果没有相交点，则会在最后相遇。
// pA:1->2->3->4->5->6->null->9->5->6->null
// pB:9->5->6->null->1->2->3->4->5->6->null

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
