/*
JZ31 栈的压入、弹出序列

描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int sz = pushV.size();
        if(sz == 0) {
            return true;
        }
        stack<int> s;
        int p_idx = 0;
        for(int i = 0; i < sz; ++i) {
            s.push(pushV[i]);
            while(!s.empty() && s.top() == popV[p_idx]) {
                s.pop();
                ++p_idx;
            }
        }
        return s.empty();
    }
/*
方法二：使用变量size来代替栈，可以降低空间复杂度
bool ispoporder(int [] pushA,int popA) {
     // size表示目前存入栈的数字数量,j 出栈数组下标
     int size = 0, j = 0;
     for (int e : pushA) {
        // 每次更新栈顶数据
          pushA[size] = e;
        // 若stack的顶部数据与popa出栈数字相同，则数据出栈
          while (size >= 0 && pushA[size] == popA[j]) {
                j++;
                size--;
          }
          size++;
     }
     return size == 0;
}
*/
};