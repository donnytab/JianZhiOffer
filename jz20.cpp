/*
JZ20 表示数值的字符串

描述
请实现一个函数用来判断字符串str是否表示数值（包括科学计数法的数字，小数和整数）。

有效数字按照下面的方式构成：
符号+整数部分+小数点+小数部分+指数E+符号+整数部分；
并且：
1.符号可有可无；
2.有效的数必须存在，有效的数可以由整数部分+小数点+小数部分或者整数部分构成；
3.指数e可有可无；但e存在时，之后必须要跟有效的数；
因此定义5个bool变量：
1.符号sign；
2.整数部分num;
3.小数点point;
4.小数部分dec；
5.指数符号exp;
按照下面的逻辑遍历：
1.符号sign、小数点point、指数符号exp当前状态为1时，表示已经存在合法的符号，之后不能再出现相同的字符；
2.符号sign只能出现在字符串的开始或者紧跟指数符号e之后，其他位置都是非法；
3.指数符号e之后不能出现小数点；
4.指数e之前和之后都必须是有效的数；
5.有效的数由(num||dec)决定，如果两个都为0，则不是有效的数；
6.出现合法的指数e之后，之后可以接符号sign和整数部分，因此要重置状态；
7.如果当前字符为数字时，根据小数点point存在状态判断当前字符属于小数位还是整数位；
8.其他字符都是非法，直接返回false；
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return bool布尔型
     */
    bool isNumeric(string s) {
        bool sign = 0;
        bool num = 0;
        bool dec = 0;
        int point = 0;
        int exp = 0;

        // remove front and end spaces
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ")+1);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                //不能出现两个符号
                if (sign) {
                    return false;
                }
                //如果符号位在最开始或者紧跟e后，是有效的符号位
                if (i == 0 || s[i - 1] == 'E' || s[i - 1] == 'e') {
                    sign = 1;
                }
                //符号不能出现在其他位置
                else {
                    return false;
                }
            } else if (s[i] == '.') {
                //点不能在e之后，并且只能存在一个点
                if (exp || point) {
                    return false;
                }
                point = 1;
            } else if (s[i] == 'e' || s[i] == 'E') {
                //如果存在一个e或者e前的数不是一个有效的整数或者小数时，错误
                if (exp || (num == 0 && dec == 0)) {
                    return false;
                }
                //否则就是有效的e，允许后面出现符号和整数
                //因此重置符号位，整数位，小数位状态，将e的标识符写为1
                else {
                    sign = 0;
                    num = 0;
                    dec = 0;
                    exp = 1;
                }
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                //如果整数位为空或者进入指数状态，要填入整数位
                if (num == 0 || exp == 1) {
                    num = 1;
                }
                //否则就是小数位，小数位有效
                else if(point) {
                    dec = 1;
                }
            }
            else {
                //其他字符直接返回
                return false;
            }
        }
        //返回是否构成了有效的整数或者小数
        return (num || dec);       
    }
};