/**
JZ6 从尾到头打印链表

描述
输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。
输入：
{1,2,3}
返回值：
[3,2,1]

*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        /* 1. REVERSE LIST
        if (head == nullptr) {
            return ret;
        }
        
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        ListNode *new_head = prev;
        while (new_head != nullptr) {
            ret.push_back(new_head->val);
            new_head = new_head->next;
        }
        */
        
        /* 2. STACK */
        stack<int> stk;
        ListNode *temp = head;
        while (temp != nullptr) {
            stk.push(temp->val);
            temp = temp->next;
        }
        
        while (!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }

        /* 3. TOO SLOW
        ListNode *curr = head;
        while (curr != nullptr) {
            ret.insert(ret.cbegin(), curr->val);
        }
        */
        return ret;
    }
};