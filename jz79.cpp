/*
JZ79 判断是不是平衡二叉树

描述
输入一棵节点数为 n 二叉树，判断该二叉树是否是平衡二叉树
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        int l_depth = depth(pRoot->left);
        int r_depth = depth(pRoot->right);
        if(abs(l_depth - r_depth) > 1) {
            return false;
        }
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    
    int depth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1; // leave node
        return max(depth(root->left), depth(root->right)) + 1;
    }
};