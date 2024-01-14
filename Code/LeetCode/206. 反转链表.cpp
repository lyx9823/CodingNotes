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

// offitial solution: https://leetcode.cn/problems/reverse-linked-list/solutions/2361282/206-fan-zhuan-lian-biao-shuang-zhi-zhen-r1jel/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return recur(head, nullptr);           // 调用递归并返回
    }
private:
    ListNode* recur(ListNode* cur, ListNode* pre) {
        if (cur == nullptr) return pre;        // 终止条件
        ListNode* res = recur(cur->next, cur); // 递归后继节点
        cur->next = pre;                       // 修改节点引用指向
        return res;                            // 返回反转链表的头节点
    }
};

