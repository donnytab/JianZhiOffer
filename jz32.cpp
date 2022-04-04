/*
JZ32 从上往下打印二叉树

不分行从上往下打印出二叉树的每个节点，同层节点从左至右打印。

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ret;
        preorder(root, ret);
        return ret;
    }
    
    void preorder(TreeNode* root, vector<int>& vec) {
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            vec.emplace_back(node->val);
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
    }
};