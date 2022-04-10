/**
JZ86 在二叉树中找到两个节点的最近公共祖先

给定一棵二叉树(保证非空)以及这棵树上的两个节点对应的val值 o1 和 o2，
请找到 o1 和 o2 的最近公共祖先节点。

 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
private:
    TreeNode* ret;
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root,int o1, int o2) {
        return dfs(root, o1, o2)->val;
    }
    
    TreeNode* dfs(TreeNode* root, int o1, int o2) {
        if(!root || root->val == o1 || root->val == o2) {
            return root;
        }
        TreeNode* left = dfs(root->left, o1, o2);
        TreeNode* right = dfs(root->right, o1, o2);
        //如果left为空，说明这两个节点在root结点的右子树上，我们只需要返回右子树查找的结果即可
        if (left == nullptr) return right;
        //同上
        if (right == nullptr) return left;
        //如果left和right都不为空，说明这两个节点一个在root的左子树上一个在root的右子树上，
        //我们只需要返回cur结点即可。
        return root;
    }
/*
    int lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ret;
    }
    
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return false;
        bool lchild = dfs(root->left, p, q);
        bool rchild = dfs(root->right, p, q);
        if((lchild && rchild) || (root->val == p->val || root->val == q->val) && (lchild || rchild)) {
            ret = root;
        }
        return lchild || rchild || (root->val == p->val || root->val == q->val);
    }
*/
};