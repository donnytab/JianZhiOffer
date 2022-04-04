/*
JZ34 二叉树中和为某一值的路径(二)

输入一颗二叉树的根节点root和一个整数expectNumber，
找出二叉树中结点值的和为expectNumber的所有路径。

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
    vector<int> path;
    vector<vector<int> > ret;
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectNumber) {
        find(root, expectNumber);
        return ret;
    }
    
    // dfs
    void find(TreeNode* node, int target) {
        if(!node) return;
        path.emplace_back(node->val);
        target -= node->val;
        if(node->left == nullptr && node->right == nullptr && target == 0) {
            ret.emplace_back(path);
        }
        find(node->left, target);
        find(node->right, target);
        path.pop_back();
    }
};