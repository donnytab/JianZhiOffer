/*
JZ67 把字符串转换成整数(atoi)

写一个函数 StrToInt，实现把字符串转换成整数这个功能
传入的字符串可能有以下部分组成:
1.若干空格
2.（可选）一个符号字符（'+' 或 '-'）
3. 数字，字母，符号，空格组成的字符串表达式
4. 若干空格
*/

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return int整型
     */
    int StrToInt(string s) {
        int ret = 0;
        int i = 0;
        int sign = 1;
        // 1. 检查空格
        while(s[i] == ' ') { ++i; }
        // 2. 检查符号
        if(s[i] == '-') { sign = -1; }
        if(s[i] == '-' || s[i] == '+') { ++i; }
        // 3. 计算数字
        while(i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';
            // 4. 处理溢出
            if(ret > INT_MAX / 10 || (ret == INT_MAX / 10 && digit > 7)) {
                return sign > 0 ? INT_MAX : INT_MIN;
            }
            ret = ret * 10 + digit;
            ++i;
        }
        return sign > 0 ? ret : -ret;
    }
};