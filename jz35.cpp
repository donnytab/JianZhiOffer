/*
JZ35 复杂链表的复制

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），
请对此链表进行深拷贝，并返回拷贝后的头结点。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(!pHead) return nullptr;
        unordered_map<RandomListNode*, RandomListNode*> umap;
        RandomListNode* dummy = new RandomListNode(-1);
        RandomListNode* curr = pHead;
        RandomListNode* prev = dummy;

        while(curr) {
            RandomListNode* node = new RandomListNode(curr->label);
            umap[curr] = node;
            prev->next = node;
            prev = prev->next;
            curr = curr->next;
        }
        
        for(auto& [old_node, new_node] : umap) {
            new_node->random = old_node->random ? umap[old_node->random] : nullptr;
        }
        
        return umap[pHead];
    }
};