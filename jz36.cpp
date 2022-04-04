/*
JZ36 二叉搜索树与双向链表

描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
    TreeNode* pre; //使用一个指针pre指向当前结点root的前继
public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(!pRootOfTree) return pRootOfTree;
        TreeNode* root = pRootOfTree;
        while(root->left) {
            root = root->left; // 找到双向链表的开头。
        }
        inorder(pRootOfTree);
        return root;
    }
    
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        root->left = pre;
        if(pre) {
            pre->right = root;
        }
        pre = root; //更新pre，指向当前结点，作为下一个结点的前继
        inorder(root->right);
        
    }
};