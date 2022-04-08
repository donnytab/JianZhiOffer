/*
JZ64 求1+2+3+...+n

求1+2+3+...+n，要求不能使用乘除法、
for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

class Solution {
public:
    // 递归变形
    int Sum_Solution(int n) {
        n && (n += Sum_Solution(n-1));  // bool x只是为了不报错
        return n;
    }
};