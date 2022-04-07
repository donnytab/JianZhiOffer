/*
JZ49 丑数

描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第 n个丑数。
*/

/*
https://leetcode-cn.com/problems/chou-shu-lcof/solution/mian-shi-ti-49-chou-shu-dong-tai-gui-hua-qing-xi-t/

丑数的递推性质： 丑数只包含因子 2, 3, 52,3,5 ，因此有 “丑数 == 某较小丑数 \times× 某因子” （例如：10 = 5 \times 210=5×2）

三指针 + 动态规划

状态定义： 设动态规划列表 dp ，dp[i] 代表第 i + 1 个丑数；

指针分别为指向下一个2,3,5可能成为下一个丑数的数的位置的指针
*/

class Solution {
public:
    int GetUglyNumber_Solution(int n) {
        if(n < 1) return 0;
        int a = 0, b = 0, c = 0;
        int dp[n];
        dp[0] = 1;
        for(int i = 1; i < n; ++i) {
            int f2 = dp[a]*2, f3 = dp[b]*3, f5 = dp[c]*5;
            dp[i] = min(f2, min(f3, f5));  // find the smallest
            if(dp[i] == f2) ++a;
            if(dp[i] == f3) ++b;
            if(dp[i] == f5) ++c;
        }
        return dp[n-1];
    }
};