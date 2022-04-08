/**
JZ68 二叉搜索树的最近公共祖先

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

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
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    /*
    递归
    递推工作：
    当 p, q都在 rootroot 的 右子树 中，则开启递归 root.right 并返回；
    否则，当 p,q 都在 root 的 左子树 中，则开启递归 root.left 并返回；
    返回值： 最近公共祖先 root 。

    时间复杂度 O(N) ： 其中 NN 为二叉树节点数；每循环一轮排除一层，二叉搜索树的层数最小为 logN （满二叉树），最大为 N （退化为链表）。
    空间复杂度 O(N) ： 最差情况下，即树退化为链表时，递归深度达到树的层数 N
    
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(root->val > p && root->val > q) {
            return lowestCommonAncestor(root->left, p, q);
        } else if(root->val < p && root->val < q) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root->val;
        }
    }
    */
    
    /*
    迭代
    循环搜索： 当节点 root 为空时跳出；
    当 p,q 都在 root 的 右子树 中，则遍历至 root.right ；
    否则，当 p,q 都在 root 的 左子树 中，则遍历至 root.left ；
    否则，说明找到了 最近公共祖先 ，跳出。
    返回值： 最近公共祖先 root 。
    时间复杂度 O(N) 
    空间复杂度 O(1)
    */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        while(root) {
           if(root->val > p && root->val > q) {
                root = root->left;
            } else if(root->val < p && root->val < q) {
                root = root->right;
            } else {
                break;
            }
        }
        return root->val;
    }
};