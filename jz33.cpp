/*
JZ33 二叉搜索树的后序遍历序列

描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则返回 true ,否则返回 false 。*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int sz = sequence.size();
        if(sz == 0) return false;
        return check(sequence, 0, sz - 1);
    }
    
    bool check(vector<int> seq, int left, int right) {
        if(left >= right) return true; // 若当前子树只有一个节点
        int root = seq[right]; //后序遍历中最后一个节点为当前子树的根节点
        int mid = left;
        while(seq[mid] < root) {
            ++mid;
        }
        int temp = mid;
        while(temp < right) {
            if(seq[temp++] < root) {    // 右子树比根节点小，错误
                return false;
            }
        }
        return check(seq, left, mid - 1) && check(seq, mid, right - 1);
    }
};

/*
栈
实际上二叉树的中序遍历和后序遍历对应着一种栈的压入、弹出序列, 而对后序遍历序列从小到大排序就得到了中序遍历序列
我们得到中序遍历序列后, 将其作为入栈序列, 检查后序遍历序列是不是一个合法的出栈序列即可
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        vector<int> inorder(sequence);
        sort(inorder.begin(), inorder.end());
        return IsPopOrder(inorder, sequence);
    }
 
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
         int n = pushV.size();
         stack<int> stk;    // 使用STL中的栈容器
         int i = 0, j = 0;
         while(i < n){
             stk.push(pushV[i]);    // 首先将pushV[i]入栈
             while(!stk.empty() && stk.top() == popV[j]){    // 不断检查栈顶
                 ++j;
                 stk.pop();
             }
             ++i;
         }
         return j == n;    // 判断能否成功对应
     }
};
*/