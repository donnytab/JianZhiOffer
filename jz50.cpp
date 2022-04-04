/*
JZ50 第一个只出现一次的字符

描述
在一个长为 字符串中找到第一个只出现一次的字符,并返回它的位置, 
如果没有则返回 -1（需要区分大小写）.（从0开始计数）
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> umap;
        for(auto const& ch : str) {
            ++umap[ch];
        }
        
        for(int i = 0; i < str.size(); ++i) {
            if(umap[str[i]] == 1) {
                return i; 
            }
        }
        return -1;
    }
};