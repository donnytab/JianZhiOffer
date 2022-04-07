/*
JZ58 左旋转字符串

汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列  S ，请你把其循环左移 K 位后的序列输出。

输入：
"abcXYZdef",3
返回值：
"XYZdefabc"
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.empty()) return str;
        int offset = n % str.size();
        str += str.substr(0, offset);
        str.erase(0, offset);
        return str;
    }
};