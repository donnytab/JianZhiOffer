/*
JZ8 二叉树的下一个结点

描述
给定一个二叉树其中的一个结点，请找出中序遍历顺序的下一个结点并且返回
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的next指针。

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
/*
暴力解法（错误）
1.根据输入的结点以及next指针，先求得二叉树的根结点root；
2.利用root进行二叉树的中序遍历，并定义数组储存中序遍历的结果；
3.遍历该数组，得到「下一个结点」。

    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr || pNode->next == pNode) {
            return nullptr;
        }

        TreeLinkNode* root = pNode;
        while(root->next) {
            root = root->next;
        }
        
        vector<TreeLinkNode*> vec;
        traverse(root, vec);
        for(int i = 0; i < vec.size(); ++i) {
            if(vec[i] == pNode && i + 1 < vec.size()) {
                return vec[i+1];
            }
        }
        return nullptr;
    }
    
    void traverse(TreeLinkNode* node, vector<TreeLinkNode*> vec) {
        if(!node) {
            return;
        }
        traverse(node->left, vec);
        vec.push_back(node);
        traverse(node->right, vec);
    }
*/
    
/*
「某结点的下一个结点」仅有二种情况：
若该结点存在右子树，则「下一个结点」为「该结点右子树的最左孩子」；
若该结点不存在右子树，则「下一个结点」为「该结点的第一个右父结点」。
*/
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(!pNode) {
            return nullptr;
        }
        if(pNode->right) {
            TreeLinkNode* rchild = pNode->right;
            while(rchild->left) {
                rchild = rchild->left;
            }
            return rchild;
        } else {
            while(pNode->next) {
                if(pNode->next->left == pNode) {
                    return pNode->next;
                }
                pNode = pNode->next;
            }
            return nullptr;
        }
    }
};