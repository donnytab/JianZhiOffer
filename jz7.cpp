/**
JZ7 重建二叉树

描述
给定节点数为 n 的二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。

输入：
[1,2,4,7,3,5,6,8],[4,7,2,1,5,3,8,6]
返回值：
{1,2,3,4,#,5,6,#,7,#,#,8}

 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int p_size = pre.size();
        int i_size = vin.size();
        if(p_size == 0 || i_size == 0 || p_size != i_size) {
            return nullptr;
        }
        return helper(pre, vin, 0, p_size - 1, 0, i_size - 1);
    }
    
    TreeNode* helper(vector<int> pre, vector<int> vin, int pre_l, int pre_r, int vin_l, int vin_r) {
        if(pre_l > pre_r) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[pre_l]);
        int in = 0;
        for(auto const& v : vin) {
            if(v == root->val) {
                break;
            }
            ++in;
        }
        int l_len = in - vin_l;
        root->left = helper(pre, vin, pre_l + 1, pre_l + l_len, vin_l, in - 1);
        root->right = helper(pre, vin, pre_l + l_len + 1, pre_r, in + 1, vin_r);
        return root;
    }
};