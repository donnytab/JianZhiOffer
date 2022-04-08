/*
JZ73 翻转单词序列

输入：
"nowcoder. a am I"
返回值：
"I am a nowcoder."
*/
class Solution {
public:
    string ReverseSentence(string str) {
        istringstream ss(str);
        string ret, s;
        while(ss >> s) {
            ret = s + ' ' + ret;
        }
        return ret.substr(0, ret.size() - 1);
    }
};