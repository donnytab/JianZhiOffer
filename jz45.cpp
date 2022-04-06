/*
JZ45 把数组排成最小的数

描述
输入一个非负整数数组numbers，
把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

如果有两个字符串a,b，
如果a + b < b + a, 显然我们希望a排在b的前面，因为a排在前面可以使结果更小。于是我们就自定义排序规则，使得vector中字符串都满足如上规则，那么最后的结果肯定是最小的。
算法步骤：

将vector<int> 转化为vector<string>
自定义上述排序规则
整合结果
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> str;
        for(auto const& val : numbers) {
            str.push_back(to_string(val));
        }
        sort(str.begin(), str.end(), [](string a, string b){
            return a + b < b + a;
        });
        string ret;
        for(string s : str) {
            ret += s;
        }
        return ret;
    }
};