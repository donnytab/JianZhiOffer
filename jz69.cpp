/*
JZ69 跳台阶

一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

class Solution {
public:
    // 每一个状态计算直接相关的只有当前值的前2个值；
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)

    int jumpFloor(int number) {
        int j1 = 1, j2 = 1, tmp = 1;
        for(int i = 2; i <= number; ++i) {
            tmp = j1 + j2;
            j1 = j2;
            j2 = tmp;
        }
        return j2;
    }

    /*
    int jumpFloor(int number) {
        int jf[number+1];
        jf[0] = 1;
        jf[1] = 1;
        for(int i = 2; i <= number; ++i) {
            jf[i] = jf[i-1] + jf[i-2];
        }
        return jf[number];
    }
    */

};