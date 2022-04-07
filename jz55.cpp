/*
JZ55 二叉树的深度

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
    // 时间复杂度：O(n) 空间复杂度：O(n),当退化到链表时
    int TreeDepth(TreeNode* pRoot) {
        if(!pRoot) return 0;
        int l = TreeDepth(pRoot->left);
        int r = TreeDepth(pRoot->right);
        return max(l, r) + 1;
    }

/*
// 层次遍历
// 时间复杂度：O(n),二叉树的每个节点遍历一次 
// 空间复杂度：O(n),最差情况下，树平衡时，队列最多存储n/2个节点
    int TreeDepth(TreeNode* pRoot) {
        if(!pRoot) return 0;
        queue<TreeNode*> q;
        q.push(pRoot);
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* node = q.top();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ++level;
        }
        return level;
    }
*/
};