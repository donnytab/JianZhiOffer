/*
JZ48 最长不含重复字符的子字符串


请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
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

// 动态规划+哈希表
/*
1.用字典来存储字符的位置
2.默认起始位置为0，最大长度为0
3.遍历字符串
   如果存在过该字符，说明可能需要更新起始位置。起始位置更新为之前该字符位置的后一个位置。（注意，起始位置只前进，不后退，所以需要取一个max）
   以当前位置结尾大最大子串的长度为起始位置到当前位置的长度（i-start+1），最大长度需要取max
4.返回最大长度
    */
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int start = 0;
        int ret = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(umap.find(s[i]) != umap.end()) {    // found char
                start = max(start, umap[s[i]] + 1);
            }
            ret = max(ret, i - start + 1);
            umap[s[i]] = i;
        }
        return ret;
    }
};