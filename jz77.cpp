/*
JZ77 按之字形顺序打印二叉树

给定一个二叉树，返回该二叉树的之字形层序遍历，
（第一层从左向右，下一层从右向左，一直这样交替）

时间复杂度：O(N) 空间复杂度：O(N)

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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ret;
        if(!pRoot) return ret;
        bool flip = false;
        queue<TreeNode*> q;
        q.push(pRoot);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> level;
            // on every level
            while(sz--) {
                TreeNode* node = q.front();
                level.emplace_back(node->val);
                if(node->left) { q.push(node->left); }
                if(node->right) { q.push(node->right); }
                q.pop();
            }
            if(flip) {
                reverse(level.begin(), level.end());
            }
            flip = !flip;
            ret.emplace_back(level);
        }
        return ret;
    }
    
};