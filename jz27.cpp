/**
JZ27 二叉树的镜像

描述
操作给定的二叉树，将其变换为源二叉树的镜像。
要求： 空间复杂度 O(n)。本题也有原地操作，即空间复杂度 O(1)的解法，时间复杂度 O(n)

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
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        if(!pRoot) {
            return nullptr;
        }
        return builder(pRoot);
    }
    
    TreeNode* builder(TreeNode* t) {
        if(!t) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(t->val);
        root->left = builder(t->right);
        root->right = builder(t->left);
        return root;
    }

/*
    // Solution 2
    TreeNode* Mirror(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* tmp = root->left;
        root->left = Mirror(root->right);
        root->right = Mirror(tmp);
        return root;
    }
    
    // Solution 3
        TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        swap(root->left, root->right);
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
    
    // Solution 4 : Using stack
    TreeNode* mirrorTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node == NULL) {
                continue;
            }
            swap(node->left, node->right);
            s.push(node->left); 
            s.push(node->right);
        }
        return root;
    }
*/
};