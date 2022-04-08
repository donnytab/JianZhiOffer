/*
JZ71 跳台阶扩展问题

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。


递归
主要分析：
1.令f(n)表示n阶台阶总的跳法
2.假设最后只跳一步，那么f(n) = f(n-1); 最后跳两步，那么f(n) = f(n-2)；
以此类推，可知总的跳法为f(n) = f(n-1) + f(n-2) +....+f(0)
    int jumpFloorII(int number) {
        int ans = 1;
        for(int i = 1; i<number;i++)
            ans += jumpFloorII(number-i);  //计算f(number-1)
        return ans;
    }
*/
class Solution {
public:
/*
题解思路：延续题解一中的公式f(n) = f(n-1) + f(n-2) +....+f(0)
分析：
1.知道f(n) = f(n-1) + f(n-2) +....+f(0)，那么f(n-1) = f(n-2) + f(n-3) +......+f(0);
2.可知 f(n) = 2 * f(n-1);
3.初始ans = 1;

最后数学推导得出 f(n) = 2^(n-1);
时间复杂度：O(1)，一次位运算
空间复杂度：O(1)，没有使用其他空间
*/
    int jumpFloorII(int number) {
        if(number == 1 || number == 0) return 1;
        return 1 << (number-1);
    }
};