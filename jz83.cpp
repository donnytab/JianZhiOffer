/*
JZ83 剪绳子（进阶版）

给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段（ m 、 n 都是整数， n > 1 并且 m > 1 ， m <= n ），
每段绳子的长度记为 k[1],...,k[m] 。
请问 k[1]*k[2]*...*k[m] 可能的最大乘积是多少

贪心解法
核心思路是：尽可能把绳子分成长度为3的小段，这样乘积最大
如果 n == 2，返回1，如果 n == 3，返回2，两个可以合并成n小于4的时候返回n - 1
如果 n == 4，返回4
如果 n > 4，分成尽可能多的长度为3的小段，每次循环长度n减去3，乘积res乘以3；最后返回时乘以小于等于4的最后一小段；每次乘法操作后记得取余就行
以上2和3可以合并
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number long长整型 
     * @return long长整型
     */
    //快速幂运算
    // 采用快速幂加快速乘法优化 二分的思维，运算次数缩减到了log2n次
    long pow (long cnt) {
        // 如何快速计算3的cnt次幂?
        if (cnt == 0) return 1;
        if (cnt == 1) return 3;
        long part = pow(cnt / 2);
        if (cnt % 2 == 0) return part * part % 998244353;
        return 3 * part * part % 998244353;
    }

    long long cutRope(long long number) {
        if (number == 2) return 1;
        if (number == 3) return 2;
        long cnt = number / 3;
        if (number % 3 == 0) {
            return pow(cnt) % 998244353;
        } else if (number % 3 == 1) {
            cnt--;
            return 2 * 2 * pow(cnt) % 998244353;
        } else {
            return 2 * pow(cnt) % 998244353;
        }
    }
};