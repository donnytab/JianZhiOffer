/*
JZ43 整数中1出现的次数（从1到n整数中1出现的次数

描述
输入一个整数 n ，求 1～n 这 n 个整数的十进制表示中 1 出现的次数
例如， 1~13 中包含 1 的数字有 1 、 10 、 11 、 12 、 13 因此共出现 6 次
*/

/*
算法

我们可以从小到大枚举 kk。如果 n \geq 10^kn≥10 
k
 ，说明 nn 包含 10^k10 
k
  对应的数位，我们通过 式计算这一数位 11 的个数并累加，否则退出枚举。

*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        long long mulk = 1;
        int ans = 0;
        for(int k = 0; n >= mulk; ++k) {
            ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
            mulk *= 10;
        }
        return ans;
    }
    
    /*
    //这个小问题主要可以分三种情况，cur 为 0、1、 2~9
        int NumberOf1Between1AndN_Solution(int n) {
        int count = 0, bitNum = 100, high = n / 100, cur = (n / 10) % 10, low = n % 10;
        if(cur == 0) {
            // case 1: cur == 0
            // cur=0时，高位需要减去一位用于低位进行计算
            // 相当于 count = (high - 1) * bitNum + (99 + 1)
            count += high * bitNum;
        } else if(cur == 1) {
            // case 2: cur == 1
            // 相当于高位+低位计算结果，即(high * bitNum) + (low + 1)    
            count += high * bitNum + low + 1;
        } else {
            // case3: cur > 1
            // 相对于cur=0的情况，就不需要高位减去一位来计算低位的结果数了
            // 相当于(high * bitNum) + (低位数结果数)
            count += (high + 1) * bitNum;
        }
        return count;
    }
    */
};