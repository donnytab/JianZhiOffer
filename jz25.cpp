/*
JZ25 合并两个排序的链表

描述
输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
要求：空间复杂度 O(1)，时间复杂度 O(n)

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1) {
            return pHead2;
        }
        if(!pHead2) {
            return pHead1;
        }
        if(pHead1->val < pHead2->val) {
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        } else {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
*/
    
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(pHead1 && pHead2) {
            if(pHead1->val < pHead2->val) {
                curr->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                curr->next = pHead2;
                pHead2 = pHead2->next;
            }
            curr = curr->next;
        }
        curr->next = pHead1 ? pHead1 : pHead2;
        return dummy->next;
    }
};