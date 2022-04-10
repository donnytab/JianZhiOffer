/*
JZ76 删除链表中重复的结点

在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针

1、由于给定的链表是排好序的，因此重复的元素在链表中出现的位置是连续的，因此我们只需要对链表进行一次遍历，就可以删除重复的元素。由于链表的头节点可能会被删除，因此我们需要额外使用一个哑节点（dummy）指向链表的头节点。
2、让指针 cur 指向链表的哑节点，随后开始对链表进行遍历。如果当前cur.next 与cur.next.next 对应的元素相同，那么我们就需要将 cur.next 以及所有后面拥有相同元素值的链表节点全部删除。我们记下这个元素值 x，随后不断将 cur.next 从链表中移除，直到 cur.next 为空节点或者其元素值不等于 x 为止。此时，我们将链表中所有元素值为 x 的节点全部删除。
3、如果当前 cur.next 与 cur.next.next 对应的元素不相同，那么说明链表中只有一个元素值为 cur.next 的节点，那么我们就可以将 cur 指向 cur.next。
当遍历完整个链表之后，我们返回链表的的哑节点的下一个节点 dummy.next 即可。
需要注意， cur.next 以及 cur.next.next 可能为空节点，如果不加以判断，可能会产生运行错误


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

/*
 -1   ->   1   ->   2   ->   2   ->   3
dummy     pHead
cur
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(!pHead) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = pHead;
        ListNode *cur = dummy;
        while(cur->next && cur->next->next) {
            if(cur->next->val == cur->next->next->val) {
                int tmp = cur->next->val;
                while(cur->next && cur->next->val == tmp) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};