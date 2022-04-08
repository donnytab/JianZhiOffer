/*
JZ65 不用加减乘除做加法

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。


模拟二进制加法

计算a和b的无进位和，和进位
如果进位不为0，则说明a+b的结果等于无进位和+进位，此时，把无进位和作为a，进位作为b，继续计算
如果进位等于0， 说明此时a+b的结果就等于无进位和，返回无进位和即可。

对于负数的情况，计算机中使用了补码作为负数在计算机中的存储。其使加法和减法统一了起来。因此模拟的二进制加法也是可行的。
A+B=A^B+(A&B)<<1;
*/
class Solution {
public:
    int Add(int num1, int num2) {
        while(num2 != 0) {
            int carry = (num1 & num2) << 1; // 求进位
            num1 ^= num2;    // 求非进位和
            num2 = carry;    // 进位
        }
        return num1;
    }
};