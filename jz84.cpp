/**
JZ84 二叉树中和为某一值的路径(三)

给定一个二叉树root和一个整数值 sum ，求该树有多少路径的的节点值之和等于 sum 。

可以使用两次dfs解决，第一次dfs遍历二叉树每个结点，每个结点都作为一次根结点，
第二次dfs遍历以每个结点为根的子树，查找该子树是否有路径和等于目标值的。


方法二：一次dfs+哈希表
两次dfs有些浪费，可以一次dfs解决。在进入以某个结点为根的子树中，向其中添加到该节点为止的路径和进入哈希表中，
相当于每次分枝下都有前面各种路径和，相当于我只要查找哈希表就可以找到从中间截断的路径，而遍历完这个分枝后依次删除这个分枝在哈希表中记录的路径和，
避免影响别的分枝，只有公共分枝的路径和才会一直记录在哈希表中。

class Solution {
public:
    unordered_map<int, int> mp; //记录路径和及条数
    int dfs(TreeNode* root, int sum, int last){ //last为到上一层为止的累加和
        if(root == NULL) //空结点直接返回
            return 0;
        int res = 0;
        int temp = root->val + last; //到目前结点为止的累加和
        if(mp.find(temp - sum) != mp.end())  //如果该累加和减去sum在哈希表中出现过，相当于减去前面的分支
            res += mp[temp - sum]; //加上有的路径数
        mp[temp]++; //增加该次路径和
        res += dfs(root->left, sum, temp); //进入子结点
        res += dfs(root->right, sum, temp);
        mp[temp]--; //回退该路径和，因为别的树枝不需要这边存的路径和
        return res;
    }
    int FindPath(TreeNode* root, int sum) {
        mp[0] = 1; //路径和为0的有1条
        return dfs(root, sum, 0);
    }
};

 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
private:
    int count = 0;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型
     */
    int FindPath(TreeNode* root, int sum) {
        if(!root) return count;
        helper(root, sum);
        FindPath(root->left, sum);
        FindPath(root->right, sum);
        return count;
    }
    
    void helper(TreeNode* node, int target) {
        if(!node) return;
        if(node->val == target) {
            ++count;
        }
        helper(node->left, target - node->val);
        helper(node->right, target - node->val);
    }
};