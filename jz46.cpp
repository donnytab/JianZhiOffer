/*
JZ46 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */

/* dp[i] 表示字符串nums中以i个位置结尾的前缀字符串的解码种数
当前字符不等于0的时候,dp[i] = dp[i-1],此时将当前位置的一个字符译码
当前字符+前一个字符，记为num, 如果 10<=num<=26 此时符合两个合并一起译码的条件；
若此时i等于1，直接dp[i]++;
大于1, 则dp[i] += dp[i-2];
举个例子： nums = "324"
此时dp[0] = 1, dp[1]呢？ dp[2]呢？
很明显nums[1] != '0'，所以dp[1] = dp[0],num = 32，此时不满足两个一起译码的条件则循环往下执行，此时 nums[2] != '0',则 dp[2] = dp[1] = 1, num = 24，此时满足两个一起译码的条件,因为i==2大于1，所以dp[2] += dp[2-2] ,dp[2] = 1+1 = 2。
*/
    int solve(string nums) {
        int sz = nums.size();
        vector<int> dp(sz + 1, 1);
        for(int i = 2; i < sz + 1; ++i) {
            int code = (nums[i-2] - '0') * 10 + (nums[i-1] - '0');
            if(code >= 10 && code <= 25) {
                dp[i] = dp[i-1] + dp[i-2];
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[sz];
    }
};