/**
JZ82 二叉树中和为某一值的路径(一)

给定一个二叉树root和一个值 sum ，判断是否有从根节点到叶子节点的节点值之和等于 sum 的路径。


 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* node, int target) {
        if(!node) return false;
        if(!node->left && !node->right && node->val == target) return true;
        return hasPathSum(node->left, target - node->val) || hasPathSum(node->right, target - node->val);
    }
    
/*
题解二： 层次遍历
题解思路： 对树进行层次遍历，遍历到叶节点，判断是否有合法路径。
算法分析：
1.首先自定义结构path_sum{TreeNode*, cur_sum}，表示到节点的路径和。
2. 每次遍历一个节点，将当前节点的val值加上父节点的cur_sum，创建一个path_sum加入队列中。
3.如果到了叶节点，某个path_sum的cur_sum属性等于sum的值。

class Solution {
public:
    struct path_sum{
        TreeNode* node;
        int cur_sum;
        path_sum(TreeNode* root = NULL, int value = 0):node(root),cur_sum(value){};
    };//自定义path_sum 用于表示到节点的路径和

    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        queue<path_sum*> q;
        path_sum* head = new path_sum(root,root->val);  //以头节点构造一个path_sum
        q.push(head);
        //队列不为空
        while(!q.empty()){
            path_sum* tmp = q.front(); // 取出一个path_sum
            q.pop();
            if(tmp->node->left==NULL&&tmp->node->right==NULL) //如果为叶子节点
            {
                if(tmp->cur_sum==sum) return true; //判断与sum的关系
            }else{
                if(tmp->node->left)//如果具有左节点
                {
                    int left_sum = tmp->node->left->val+tmp->cur_sum;
                    path_sum* left = new path_sum(tmp->node->left,left_sum);
                    q.push(left);
                }
                if(tmp->node->right)//如果有右节点
                {
                    int right_sum = tmp->node->right->val+tmp->cur_sum;
                    path_sum* right = new path_sum(tmp->node->right,right_sum);
                    q.push(right);
                }    
            }
        }
        return false;
    }
};

*/
};