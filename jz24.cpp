/*
JZ24 反转链表

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
/*
    // Recursion
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead || !pHead->next) {
            return pHead;
        }
        ListNode* reverse = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return reverse;
    }
*/
    // Iteration
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* curr = pHead;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};