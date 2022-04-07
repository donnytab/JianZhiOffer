/*
JZ52 两个链表的第一个公共结点

输入两个无环的单向链表，找出它们的第一个公共结点，如果没有公共节点则返回空。

双指针法
时间复杂度：O(m+n), m，n分别为链表A，B的长度，最坏情况下，公共结点为最后一个，需要遍历m+n个结点
空间复杂度：O(1)

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2) {
            return nullptr;
        }
        ListNode *node1 = pHead1, *node2 = pHead2;
        while(node1 != node2) {
            node1 = node1 ? node1->next : pHead2;
            node2 = node2 ? node2->next : pHead1;
        }
        return node1;
    }
};