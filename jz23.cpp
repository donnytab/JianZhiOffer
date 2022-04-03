/*
JZ23 链表中环的入口结点

描述
给一个长度为n链表，若其中包含环，请找出该链表的环的入口结点，否则，返回null。

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        if(!pHead) {
            return nullptr;
        }
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while(true) {
            if(fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                break;
            }
        }
        fast = pHead;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};