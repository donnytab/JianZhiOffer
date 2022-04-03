/*
JZ28 对称的二叉树

描述
给定一棵二叉树，判断其是否是自身的镜像（即：是否对称）

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if(!pRoot) return true;
        return helper(pRoot->left, pRoot->right);
    }
    
    bool helper(TreeNode* lTree, TreeNode* rTree) {
        if(!lTree && !rTree) return true;
        if(!lTree || !rTree) return false;
        if(lTree->val != rTree->val) return false;
        return helper(lTree->right, rTree->left) && helper(lTree->left, rTree->right);
    }

};