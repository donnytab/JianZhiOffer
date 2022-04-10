/*
JZ78 把二叉树打印成多行

给定一个节点数为 n 二叉树，要求从上到下按层打印二叉树的 val 值，同一层结点从左至右输出，每一层输出一行，
将输出的结果存放到一个二维数组中返回。

输入：
{1,2,3,#,#,4,5}
返回值：
[[1],[2,3],[4,5]]

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
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty()) {
                int sz = q.size();
                vector<int> level;
                while(sz--) {
                    TreeNode* node = q.front();
                    q.pop();
                    level.emplace_back(node->val);
                    if(node->left) { q.push(node->left); }
                    if(node->right) { q.push(node->right); }
                }
                ret.emplace_back(level);
            }
            return ret;
        }
    
};