/**
JZ54 二叉搜索树的第k个节点

给定一棵结点数为n 二叉搜索树，请找出其中的第 k 小的TreeNode结点值。

 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int KthNode(TreeNode* proot, int k) {
        if(!proot || k <= 0) return -1;
        vector<int> tmp;
        inorder(proot, tmp);
        if(k > tmp.size()) return -1;
        return tmp[k-1];
    }
    
    void inorder(TreeNode* root, vector<int>& vec) {
        if(!root) return;
        inorder(root->left, vec);
        vec.emplace_back(root->val);
        inorder(root->right, vec);
    }
};