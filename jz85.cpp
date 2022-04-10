/*
JZ85 连续子数组的最大和(二)

输入一个长度为n的整型数组array，数组中的一个或连续多个整数组成一个子数组，
找到一个具有最大和的连续子数组。
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    // 时间复杂度：O(n)，两次遍历，最坏情况下遍历两次数组
    // 空间复杂度：O(n)，动态规划辅助数组长度为n
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        vector<int> ret;
        vector<int> dp(array.size(), 0); //记录到下标i为止的最大连续子数组和
        dp[0] = array[0];
        int maxsum = dp[0];
        int left = 0, right = 0; //滑动区间
        int retl = 0, retr = 0; //记录最长的区间
        for(int i = 1; i < array.size(); ++i) {
            ++right;
            dp[i] = max(dp[i-1]+array[i], array[i]);
            if(dp[i-1] + array[i] < array[i]) { //区间新起点
                left = right;
            }
            if(dp[i] > maxsum || dp[i] == maxsum && (right-left) > (retr-retl)) {
                //更新最大值
                maxsum = dp[i];
                retl = left;
                retr = right;
            }
        }
        for(int i = retl; i <= retr; ++i) {
            ret.emplace_back(array[i]);
        }
        return ret;
    }
};

/*
方法二：动态规划空间优化
方法一虽然时间复杂度达到了进阶要求，但是使用O(n)的空间。

我们注意到动态规划在状态转移的时候只用到了i−1的信息，因此我们可以使用两个变量迭代来代替数组，
状态转移的时候更新变量y，该轮循环结束的再更新x为y即可做到每次迭代都是上一轮的dp。

class Solution {
public:
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        vector<int> res;
        int x = array[0];
        int y = 0;
        int maxsum = x;
        int left = 0, right = 0; //滑动区间
        int resl = 0, resr = 0; //记录最长的区间
        for(int i = 1; i < array.size(); i++){
            right++;
            y = max(x + array[i], array[i]); //状态转移：连续子数组和最大值
            if(x + array[i] < array[i]) //区间新起点
                left = right;
            if(y > maxsum || y == maxsum && (right - left + 1) > (resr - resl + 1)){ //更新最大值
                maxsum = y;
                resl = left;
                resr = right;
            }
            x = y; //更新x的状态
        }
        for(int i = resl; i <= resr; i++) //取数组
            res.push_back(array[i]);
        return res;
    }
};

*/