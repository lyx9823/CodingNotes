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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;

        // 单独考虑头结点: 从头结点开始循环至不等于val的第一个结点
        while(head->val == val) {
            head = head->next;
            if(head == nullptr) {
                return nullptr;
            }
        }
        
        ListNode* res = head;
        while(res->next != nullptr) {
            // 如果下一个结点的值==val, 跳过
            if((res->next)->val == val) {
                res->next = res->next->next;
            } else {  // !=val, 继续往后遍历
                res = res->next;
            }
        }
        return head;
    }
};

// 递归 https://leetcode.cn/problems/remove-linked-list-elements/solutions/10957/203yi-chu-lian-biao-yuan-su-by-lewis-dxstabdzew/
class Solution {
    public ListNode removeElements(ListNode head, int val) {
       if(head==null)
           return null;
        head.next=removeElements(head.next,val);
        if(head.val==val){
            return head.next;
        }else{
            return head;
        }
    }
}


