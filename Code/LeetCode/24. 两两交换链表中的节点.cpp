// my solution
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
    ListNode* swapPairs(ListNode* head) {
        if((head == nullptr) || (head->next==nullptr))
            return head;
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* pre = dummyhead;
        while((pre->next != nullptr) && (pre->next->next != nullptr)) {
            ListNode* left = pre->next;
            ListNode* right = pre->next->next;
            pre->next = right;
            left->next = right->next;
            right->next = left;
            pre = left;
        }
        ListNode* res = dummyhead->next;
        return res;
    }
};

// offitial solution1 迭代: https://leetcode.cn/problems/swap-nodes-in-pairs/solutions/444474/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-91/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = dummyHead;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }
};

// offitial solution2 递归:
var swapPairs = function (head) {
    if (!head || !head.next) return head
    var one = head
    var two = one.next
    var three = two.next

    two.next = one
    one.next = swapPairs(three)

    return two
};
