/*
JZ5 替换空格

描述
请实现一个函数，将一个字符串s中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

数据范围:0 \le len(s) \le 1000 \0≤len(s)≤1000 。保证字符串中的字符为大写英文字母、小写英文字母和空格中的一种。

示例1
输入：
"We Are Happy"
返回值：
"We%20Are%20Happy"
示例2
输入：
" "
返回值：
"%20"
*/
#define SPACE_REPLACEMENT "%20"
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        string ans;
        for(auto const& c : s) {
            if(c == ' ') {
                ans.append(SPACE_REPLACEMENT);
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};