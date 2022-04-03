/*
JZ26 树的子结构

描述
输入两棵二叉树A，B，判断B是不是A的子结构。（我们约定空树不是任意一个树的子结构）

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(!pRoot1 || !pRoot2) {
            return false;
        }
        return helper(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
    bool helper(TreeNode* t1, TreeNode* t2) {
        if(!t2) {
            return true;
        }
        if(!t1) {
            return false;
        }
        if(t1->val != t2->val) {
            return false;
        }
        return helper(t1->left, t2->left) && helper(t1->right, t2->right);
    }
};