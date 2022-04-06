/*
JZ44 数字序列中某一位的数字

描述
数字以 0123456789101112131415... 的格式作为一个字符序列，
在这个序列中第 2 位（从下标 0 开始计算）是 2 ，第 10 位是 1 ，第 13 位是 1 ，
以此类题，请你输出第 n 位对应的数字。
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     
思路：数学
先观察数字规律
小于10，1~9，9个数字，9位
小于100，10~99，90个数字，180位
小于1000，100~999，900个数字，2700位
    1-9       9个*1
    10-99     90个*2
    100-999   900个*3
    1000-9999 9000个*4
     */
    int findNthDigit(int n) {
        int digit = 1; // 位数
        long long start = 1;
        long long count = 9; //记录区间个数，比如9 90 900
        while(n > count) { //先减去前面有规律的数
            n -= count;
            ++digit;
            start *= 10;
            count = start * digit * 9;
        }
        //以下就是n剩余的数
        //这里我们先判断剩余的n是在哪个数
        //start就是开始的第一个数字，所以后面要n-1
        int num = start + (n - 1) / digit;
        string s = to_string(num);
        int ret = s[(n-1)%digit] - '0';
        return ret;
    }
};